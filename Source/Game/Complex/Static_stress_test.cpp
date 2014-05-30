#include "Static_stress_test.hpp"
#include "Resources/Resource_manager.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Static_prop.hpp"
#include "Scene/Model.hpp"
#include "Math/Quaternion.inl"

namespace scene
{

bool Static_stress_test::init(Scene& scene, Resource_manager& resource_manager)
{
	Handle<scene::Model> model = resource_manager.load<scene::Model>("Models/Cube.sum");

	Handle<scene::Material> materials[] =
	{
		resource_manager.load<scene::Material>("Materials/Cobblestone.material"),
		resource_manager.load<scene::Material>("Materials/Stones.material"),
		resource_manager.load<scene::Material>("Materials/Slate_tiles.material")
	};

	const size_t num_x = 32;
	const size_t num_y = 4;
	const size_t num_z = 32;

	const float3 spacing(1.25f, 1.25f, 1.25f);

	size_t counter = 0;

	float3 pos(0.f, -float(num_y) * 0.5f * spacing.y, 0.f);

	const float3 scale(0.5f, 0.5f, 0.5f);

	for (size_t y = 0; y < num_y; ++y)
	{
		pos.z = -float(num_z) * 0.5f * spacing.z;

		for (size_t z = 0; z < num_z; ++z)
		{
			pos.x = -float(num_x) * 0.5f * spacing.x;

			for (size_t x = 0; x < num_x; ++x, ++counter)
			{
				scene::Static_prop* prop = scene.create_static_prop();
				prop->create_surfaces(model, 1, &materials[counter % 3]);
				prop->set_world_transformation(pos, float3(1.f, 1.f, 1.f), float3x3::identity);

				pos.x += spacing.x;
			}

			pos.z += spacing.z;
		}

		pos.y += spacing.y;
	}

	{
		scene::Light* light = scene.create_light(scene::Light::Type::Directional);

		light->set_color(rendering::Color3(0.6f, 0.5f, 0.4f));
		light->set_lumen(1.f);
		light->set_casts_shadow(false);
		quaternion rot;
		set_rotation(rot, normalize(float3(-1.f, 1.f, -1.f)), 1.f);
		light->set_local_rotation(rot);
		light->fix_world_transformation();
	}
/*
	{
		scene::Light* light = scene.create_light(scene::Light::Type::Point);
		light->set_color(rendering::Color3(1.f, 0.f, 0.f));
		light->set_lumen(30.f);
		light->set_casts_shadow(false);
		light->set_local_position(float3(0.f, 4.f, 0.f));
		light->fix_world_transformation();
	}
*/
	
	return true;
}

Complex *Static_stress_test_factory::create_complex()
{
	return new Static_stress_test;
}

}
