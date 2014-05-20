#include "Interpolation_test.hpp"
#include "Resources/Resource_manager.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Model.hpp"
#include "Scene/Actor.hpp"

namespace scene
{

Interpolation_test::Interpolation_test() : m_angle(0.f)
{}

bool Interpolation_test::init(Scene& scene, Resource_manager& resource_manager)
{
	Handle<Model> model = resource_manager.load<Model>("Models/Cube.sum");

	Handle<Material> materials[2];

	materials[0] = resource_manager.load<Material>("Materials/Stones.material");
	materials[1] = resource_manager.load<Material>("Materials/Colors/Gold.material");

	m_actor_a = scene.create_actor();
    m_actor_a->create_surfaces(model, 1, &materials[0]);
	m_actor_a->set_local_position(float3(-2.f, 0.f, 0.f));

	m_actor_b = scene.create_actor();
    m_actor_b->create_surfaces(model, 1, &materials[1]);
	m_actor_b->set_local_scale(float3(0.25f, 0.25f, 0.25f));
	m_actor_b->set_local_position(float3(0, 1.5f, 0.f));

	m_actor_a->attach(m_actor_b);

	return true;
}

void Interpolation_test::on_tick()
{
	Quaternion rotation_y;
	set_rotation_y(rotation_y, m_angle);

	m_actor_a->set_local_position(float3(-2.f, 0.f, 0.f) * float3x3(rotation_y));
	m_actor_a->set_local_rotation(rotation_y);

	Quaternion rotation_x;
	set_rotation_x(rotation_x, m_angle);

	m_actor_b->set_local_position(float3(0, 1.5f, 0.f) * float3x3(rotation_x));
	m_actor_b->set_local_rotation(rotation_x);

	m_angle += 0.03f;
}

Complex* Interpolation_test_factory::create_complex()
{
	return new Interpolation_test;
}

}
