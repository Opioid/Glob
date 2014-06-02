#include "Shadowing_test.hpp"
#include "Scene/Scene.hpp"
#include "Resources/Resource_manager.hpp"
#include "Scene/Static_prop.hpp"
#include "Scene/Model.hpp"
#include "Scene/Material.hpp"
#include "Rendering/Resource_view.hpp"
#include "Math/Quaternion.inl"
#include "Math/Math.hpp"

namespace scene
{

bool Shadowing_test::init(Scene& scene, Resource_manager& resource_manager)
{
    Handle<Model> models[2];
    models[0] = resource_manager.load<Model>("Models/Tile.sum");
    models[1] = resource_manager.load<Model>("Models/Cube.sum");

	Handle<Material> materials[2];
	materials[0] = resource_manager.load<Material>("Materials/Colors/Light_gray.material");
	materials[1] = resource_manager.load<Material>("Materials/Grid_2x2.material");

	size_t num_x = 100;
 //   size_t num_y = 10;
	size_t num_z = 100;

    float3 interval = float3(2.f, 1.f, 2.f);
    float3 offset = -0.5f * float3(float(num_x), 0.f, float(num_z));

    for (size_t z = 0; z < num_z; ++z)
	{
        for (size_t x = 0; x < num_x; ++x)
		{
			Static_prop* prop = scene.create_static_prop();

			prop->create_surfaces(models[0], 1, &materials[1]);

			float3 position = float3(float(x), -1.f, float(z));

            prop->set_world_transformation((offset + position) * interval, float3(2.f, 1.f, 2.f), float3x3::identity);
		}
	}

    offset = float3(1.f, 0.f, -0.5f * float(num_z));
	interval = float3(1.f, 1.f, 2.f);

    for (size_t z = 0; z < num_z; ++z)
	{
		Static_prop* prop = scene.create_static_prop();

		prop->create_surfaces(models[1], 1, &materials[0]);

		float3 position(-2.f, 1.f, float(z));
		float3 scale(0.4f, 4.f, 2.f);

		prop->set_world_transformation((offset + position) * interval, scale, float3x3::identity);
	}

	{
		Light* light = scene.create_light(Light::Type::Directional);
		light->set_casts_shadow(true);
        light->set_color(rendering::Color3(1.f, 0.875f, 0.8f));
        light->set_lumen(1.f);
		quaternion rot;
		::set_rotation(rot, float3(-1.f, -1.f, -1.f), 1.f);
		light->set_local_rotation(rot);
	}

	{
		Light* light = scene.create_light(Light::Type::Spot);
		light->set_casts_shadow(true);
		light->set_color(rendering::Color3(1.f, 1.f, 1.f));
		light->set_lumen(80.f);
		light->set_texture(resource_manager.load<rendering::Shader_resource_view>("Textures/Light/Flashlight_0.dds"));
		light->set_fov(math::to_radians(45.f));
		light->set_local_position(float3(9.5f, 8.f, 7.5f));
		quaternion rot;
		::set_rotation(rot, float3(-1.f, 1.f, -1.f), 1.f);
		light->set_local_rotation(rot);
	}
    /*
	{
		Light *light = scene.create_light(Light::Type::Point);
		light->set_casts_shadow(false);
		light->set_color(rendering::Color3(2.f, 0.f, 0.f));
		light->set_local_position(float3(0.f, 8.f, 15.f));
	}
    */
	return true;
}


Complex* Shadowing_test_factory::create_complex()
{
    return new Shadowing_test;
}

}
