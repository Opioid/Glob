#include "Material_test.hpp"
#include "Resources/Resource_manager.hpp"
#include "Scene/Scene.hpp"
#include "Scene/Static_prop.hpp"
#include "Scene/Model.hpp"

namespace scene
{

bool Material_test::init(Scene& scene, Resource_manager& resource_manager)
{
	Handle<Model> sphereModel = resource_manager.load<Model>("Models/Sphere.sum");
	Handle<Model> cubeModel = resource_manager.load<Model>("Models/Cube.sum");
	Handle<Model> levelModel = resource_manager.load<Model>("Models/Tile.sum");
	
	Handle<Material> materials[4];
	
	materials[0] = resource_manager.load<Material>("Materials/Colors/Red.material");//resource_manager.load<Material>("Materials/Colors/Lavender.material");
	materials[1] = resource_manager.load<Material>("Materials/Chesterfield.material");
/*	materials[2] = resource_manager.load<Material>("Materials/Colors/TranslucentWhite.material.yaml");
	materials[3] = resource_manager.load<Material>("Materials/Bronze.material.yaml");
	*/

	if (!materials[0])
	{
		return false;
	}
	
	const size_t numX = 10;
	const size_t numY = 10;

	for (size_t y = 0; y < numY; ++y)
	{
		for (size_t x = 0; x < numX; ++x)
		{
			Handle<Material> material = resource_manager.clone<Material>(materials[0]);

			material->set_metallic(float(x) / float(numX - 1));

			material->set_roughness(1.f - float(y) / float(numY - 1));

			Actor* actor = scene.create_actor();
			actor->create_surfaces(sphereModel, 1, &material);
			actor->set_local_position(float3(1.f - float(numX) + 2.f * float(x), 1.f - float(numY) + 2.f * float(y), 13.f));
		//	Actor->set_world_transformation(float3(1.f - float(numX) + 2.f * float(x), 1.f - float(numY) + 2.f * float(y), 13.f), float3(1.f, 1.f, 1.f), float3x3::identity);
		}
	}

	/*
	Light* light = scene.create_light(Light::Type::Directional);
	light->set_color(rendering::Color3(1.f, 1.f, 1.f));
	light->set_lumen(0.75f);
	light->set_casts_shadow(true);
	Quaternion rot;
	::set_rotation(rot, normalize(float3(-1.f, 1.f, 1.f)), 1.f);
	light->set_local_rotation(rot);
	*/
	/*
	Light* pointLight = scene.create_light(Light::Type::Point);
	pointLight->set_energy(Color3(5.f, 0.f, 0.f));
	pointLight->setPosition(float3(0.f, 5.f, 5.f));
	
	pointLight = scene.create_light(Light::Type::Point);
	pointLight->set_energy(Color3(0.f, 5.f, 0.f));
	pointLight->setPosition(float3(-2.f, 2.f, 7.f));
	*/
	return true;
}


Complex* Material_test_factory::create_complex()
{
	return new Material_test;
}

}
