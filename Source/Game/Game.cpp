#include "Game.hpp"
#include "Camera.hpp"
#include "Application/Application.hpp"
#include "Application/Configuration.hpp"
#include "Scene/Actor.hpp"
#include "Math/Math.hpp"
#include "Complex/Material_test.hpp"
#include "Complex/Shadowing_test.hpp"
#include "Complex/Static_stress_test.hpp"
#include "Rendering/Storage/Texture_storage_save.hpp"

namespace game
{

Camera game_camera;

scene::Light* flashlight;

scene::Material_test_factory material_test_factory;
scene::Shadowing_test_factory shadowing_test_factory;
scene::Static_stress_test_factory static_stress_test_factory;

std::string initial_scene = "Scenes/Test.scene";
float camera_fov = 50.f;

bool on_pre_init(Application& application)
{
	const scripting::Script_engine& engine = application.script_tool().engine();
		
	engine.register_variable("string initial_scene", &initial_scene);

	engine.register_variable("float camera_fov", &camera_fov);

	return true;
}

bool on_post_init(Application& application)
{
	auto& scene = application.scene();

	scene.complex_factories().register_factory(&material_test_factory, "Material_test");
	scene.complex_factories().register_factory(&shadowing_test_factory, "Shadowing_test");
	scene.complex_factories().register_factory(&static_stress_test_factory, "Static_stress_test");

	auto& camera = scene.camera();

	float aspect_ratio = float(configuration::virtual_dimensions.x) / float(configuration::virtual_dimensions.y);
	camera.set_projection(math::to_radians(camera_fov), aspect_ratio, 0.1f, 300.f, false);

	camera.set_local_position(float3(0.f, 1.f, -10.f));
		
	if (!application.load_scene(initial_scene))
	{
		return false;
	}

	return true;
}

void on_load_scene(Application& application)
{
	auto& scene = application.scene();
	auto& resource_manager = application.resource_manager();

	flashlight = scene.create_light(scene::Light::Type::Spot);
	flashlight->set_casts_shadow(true);
	flashlight->set_color(rendering::Color3(1.f, 1.f, 1.f));
	flashlight->set_lumen(15.f);
	flashlight->set_texture(resource_manager.load<rendering::Shader_resource_view>("Textures/Light/Flashlight_0.dds"));
	flashlight->set_fov(math::to_radians(30.f));
	flashlight->set_visible(false);
}

void update(Application& application, float /*time_slice*/)
{
	auto& camera = application.scene().camera();

	flashlight->set_local_position(camera.world_position() + 0.2f * camera.world_direction() + -0.2f * camera.world_right() + -0.2f * camera.world_up());
	flashlight->set_local_rotation(camera.local_rotation());
    flashlight->fix_world_transformation();
}

Camera& camera()
{
	return game_camera;
}

void toggle_flashlight(bool just_activated, int /*data*/, float /*speed*/)
{
	if (just_activated)
	{
		flashlight->set_visible(!flashlight->is_visible());
	}
}

}
