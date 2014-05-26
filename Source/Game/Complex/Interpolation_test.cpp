#include "Interpolation_test.hpp"
#include "Resources/Resource_manager.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Model.hpp"
#include "Scene/Actor.hpp"

namespace scene
{

Interpolation_test::Interpolation_test() : angle_(0.f)
{}

bool Interpolation_test::init(Scene& scene, Resource_manager& resource_manager)
{
	Handle<Model> model = resource_manager.load<Model>("Models/Cube.sum");

	Handle<Material> materials[2];

	materials[0] = resource_manager.load<Material>("Materials/Stones.material");
	materials[1] = resource_manager.load<Material>("Materials/Colors/Gold.material");

	actor_a_ = scene.create_actor();
    actor_a_->create_surfaces(model, 1, &materials[0]);
	actor_a_->set_local_position(float3(-2.f, 0.f, 0.f));

	actor_b_ = scene.create_actor();
    actor_b_->create_surfaces(model, 1, &materials[1]);
	actor_b_->set_local_scale(float3(0.25f, 0.25f, 0.25f));
	actor_b_->set_local_position(float3(0, 1.5f, 0.f));

	actor_a_->attach(actor_b_);

	return true;
}

void Interpolation_test::on_tick(float /*time_slice*/)
{
	Quaternion rotation_y;
	set_rotation_y(rotation_y, angle_);

	actor_a_->set_local_position(float3(-2.f, 0.f, 0.f) * float3x3(rotation_y));
	actor_a_->set_local_rotation(rotation_y);

	Quaternion rotation_x;
	set_rotation_x(rotation_x, angle_);

	actor_b_->set_local_position(float3(0, 1.5f, 0.f) * float3x3(rotation_x));
	actor_b_->set_local_rotation(rotation_x);

	angle_ += 0.03f;
}

Complex* Interpolation_test_factory::create_complex()
{
	return new Interpolation_test;
}

}
