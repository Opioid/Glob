#include "Controls.hpp"
#include "Core/Core.hpp"
#include "Game/Game.hpp"
#include "Game/Camera.hpp"
#include "Logging/Logging.hpp"

namespace controls
{
	core::Glob_app* app;

	void exit_action(bool just_activated, int data, float speed);

	void cycle_application_mode(bool just_activated, int data, float speed);
	void toggle_gui(bool just_activated, int data, float speed);

	void toggle_render_bounding_volumes(bool just_activated, int data, float speed);
	void toggle_render_help_light(bool just_activated, int data, float speed);
//	void toggleRenderTest(bool just_activated, int data, float speed);

	void move_forward(bool just_activated, int data, float speed);
	void move_backward(bool just_activated, int data, float speed);
	void strafe_left(bool just_activated, int data, float speed);
	void strafe_right(bool just_activated, int data, float speed);
	void move_up_y(bool just_activated, int data, float speed);
	void move_down_y(bool just_activated, int data, float speed);

	void rotate_y(bool just_activated, int data, float speed);
	void rotate_z(bool just_activated, int data, float speed);

	void turn_left(bool just_activated, int data, float speed);
	void turn_right(bool just_activated, int data, float speed);
	void turn_up(bool just_activated, int data, float speed);
	void turn_down(bool just_activated, int data, float speed);

	void lock_camera(bool just_activated, int data, float speed);
	void unlock_camera();

	bool init(core::Glob_app* application)
	{
		app = application;

		auto& mappings = app->get_control_mappings();

		mappings.register_action("exit_action", exit_action);
		mappings.register_action("cycle_application_mode", cycle_application_mode);
		mappings.register_action("toggle_gui", toggle_gui);
		mappings.register_action("toggle_render_bounding_volumes", toggle_render_bounding_volumes);
		mappings.register_action("toggle_render_help_light", toggle_render_help_light);
	//	mappings.register_action("toggleRenderTest", toggleRenderTest);

		mappings.register_action("move_forward", move_forward);
		mappings.register_action("move_backward", move_backward);
		mappings.register_action("strafe_left", strafe_left);
		mappings.register_action("strafe_right", strafe_right);
		mappings.register_action("move_up_y", move_up_y);
		mappings.register_action("move_down_y", move_down_y);

		mappings.register_action("rotate_y", rotate_y);
		mappings.register_action("rotate_z", rotate_z);

		mappings.register_action("turn_left", turn_left);
		mappings.register_action("turn_right", turn_right);
		mappings.register_action("turn_up", turn_up);
		mappings.register_action("turn_down", turn_down);

		mappings.register_action("camera_lock", lock_camera, unlock_camera);

		mappings.register_action("toggle_flashlight", game::toggle_flashlight);

		mappings.map_action("Simulation", "exit_action", platform::key::Escape);
		mappings.map_action("Edit",       "exit_action", platform::key::Escape);

		mappings.map_action("Simulation", "toggle_gui", platform::key::F1);
		mappings.map_action("Edit",       "toggle_gui", platform::key::F1);
		mappings.map_action("Gui",        "toggle_gui", platform::key::F1);

		mappings.map_action("Simulation", "cycle_application_mode", platform::key::F2);
		mappings.map_action("Edit",       "cycle_application_mode", platform::key::F2);

		mappings.map_action("Simulation", "toggle_render_bounding_volumes", platform::key::F5);
		mappings.map_action("Edit",       "toggle_render_bounding_volumes", platform::key::F5);

		mappings.map_action("Simulation", "toggle_render_help_light", platform::key::F6);
		mappings.map_action("Edit",       "toggle_render_help_light", platform::key::F6);
/*
		mappings.map_action("Simulation", "toggleRenderTest", VK_F4);
		mappings.map_action("Edit", "toggleRenderTest", VK_F4);
*/
		mappings.map_action("Simulation", "move_forward",  platform::key::W);
		mappings.map_action("Edit",       "move_forward",  platform::key::W);
        mappings.map_action("Simulation", "move_backward", platform::key::S);
		mappings.map_action("Edit",       "move_backward", platform::key::S);
		mappings.map_action("Simulation", "strafe_left",   platform::key::A);
		mappings.map_action("Edit",       "strafe_left",   platform::key::A);
		mappings.map_action("Simulation", "strafe_right",  platform::key::D);
		mappings.map_action("Edit",       "strafe_right",  platform::key::D);
		mappings.map_action("Simulation", "move_up_y",     platform::key::Left_shift);
		mappings.map_action("Edit",       "move_up_y",     platform::key::Left_shift);
		mappings.map_action("Simulation", "move_down_y",   platform::key::Left_control);
		mappings.map_action("Edit",       "move_down_y",   platform::key::Left_control);

		mappings.map_action("Simulation", "turn_left", 	platform::key::Left);
		mappings.map_action("Simulation", "turn_right", platform::key::Right);
		mappings.map_action("Simulation", "turn_up", 	platform::key::Up);
		mappings.map_action("Simulation", "turn_down", 	platform::key::Down);

        mappings.map_action("Simulation", "rotate_y", platform::motion::Mouse_x);
		mappings.map_action("Edit",       "rotate_y", platform::motion::Mouse_x);
        mappings.map_action("Simulation", "rotate_z", platform::motion::Mouse_y);
		mappings.map_action("Edit",       "rotate_z", platform::motion::Mouse_y);

		mappings.map_action("Edit", "camera_lock", platform::key::Space);

        mappings.map_action("Simulation", "toggle_flashlight", platform::key::F);

		mappings.set_current_map("Simulation");

		return true;
	}

    void exit_action(bool just_activated, int /*data*/, float /*speed*/)
	{
		if (!just_activated)
		{
			return;
		}

		app->request_close();
	}

	void exit_on_release()
	{
		app->request_close();
	}

	void cycle_application_mode(bool just_activated, int /*data*/, float /*speed*/)
	{
		if (!just_activated)
		{
			return;
		}

		if (Application::Mode::Simulation == app->get_mode())
		{
			app->set_mode(Application::Mode::Edit);

			app->get_control_mappings().set_current_map("Edit");
			game::get_camera().set_locked(false);
		}
		else if (Application::Mode::Edit == app->get_mode())
		{
			app->set_mode(Application::Mode::Simulation);
			app->get_control_mappings().set_current_map("Simulation");
			game::get_camera().set_locked(false);
		}
	}

    void toggle_gui(bool just_activated, int /*data*/, float /*speed*/)
	{
		if (!just_activated)
		{
			return;
		}

		if (app->toggle_gui())
		{
			app->get_control_mappings().set_current_map("Gui");
		}
		else
		{
			if (Application::Mode::Simulation == app->get_mode())
			{
				app->get_control_mappings().set_current_map("Simulation");
			}
			else if (Application::Mode::Edit == app->get_mode())
			{
				app->get_control_mappings().set_current_map("Edit");
			}
		}
	}

    void toggle_render_bounding_volumes(bool just_activated, int /*data*/, float /*speed*/)
	{
		if (!just_activated)
		{
			return;
		}

		app->get_renderer().set_render_bounding_volumes(!app->get_renderer().get_render_bounding_volumes());
	}

	void toggle_render_help_light(bool just_activated, int /*data*/, float /*speed*/)
	{
		if (!just_activated)
		{
			return;
		}

		app->get_renderer().set_render_help_light(!app->get_renderer().get_render_help_light());
	}

/*
	void toggleRenderTest(bool just_activated, int data, float speed)
	{
		if (!just_activated)
		{
			return;
		}

		app->getRenderer().toggleRenderTest();
	}
	*/
	
    void move_forward(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		float camera_speed = game_camera.get_speed();

		scene::Camera& camera = app->get_scene().get_camera();
		camera.translate(speed * camera_speed * camera.get_world_direction());
	//	scene::scene.translate(scene::camera0, speed * scene::camera0.getSpeed() * scene::camera0.get_world_dir());
	}

    void move_backward(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		float camera_speed = game_camera.get_speed();

		scene::Camera& camera = app->get_scene().get_camera();
		camera.translate(speed * camera_speed * -camera.get_world_direction());
	//	scene::scene.translate(scene::camera0, speed * scene::camera0.getSpeed() * -scene::camera0.get_world_dir());
	}

    void strafe_left(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		float camera_speed = game_camera.get_speed();

		scene::Camera& camera = app->get_scene().get_camera();
		camera.translate(speed * camera_speed * -camera.get_world_right());
	//	scene::scene.translate(scene::camera0, speed * scene::camera0.getSpeed() * -scene::camera0.get_world_right());
	}

    void strafe_right(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		float camera_speed = game_camera.get_speed();

		scene::Camera& camera = app->get_scene().get_camera();
		camera.translate(speed * camera_speed * camera.get_world_right());
	//	scene::scene.translate(scene::camera0, speed * scene::camera0.getSpeed() * scene::camera0.get_world_right());
	}

    void move_up_y(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		float camera_speed = game_camera.get_speed();

		scene::Camera& camera = app->get_scene().get_camera();
		camera.translate(speed * camera_speed * float3(0.f, 0.5f, 0.f));
	}

    void move_down_y(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		float camera_speed = game_camera.get_speed();

		scene::Camera& camera = app->get_scene().get_camera();
		camera.translate(speed * camera_speed * float3(0.f, -0.5f, 0.f));
	}

    void rotate_y(bool /*just_activated*/, int data, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		scene::Camera& camera = app->get_scene().get_camera();
        camera.rotate(0.f, -float(data) * speed * 2.5f, 0.f);
	}

    void rotate_z(bool /*just_activated*/, int data, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		scene::Camera& camera = app->get_scene().get_camera();
        camera.rotate(-float(data) * speed * 2.5f, 0.f, 0.f);
	}

    void turn_left(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		scene::Camera& camera = app->get_scene().get_camera();
		camera.rotate(0.f, speed * 1.5f, 0.f);
	}

    void turn_right(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		scene::Camera& camera = app->get_scene().get_camera();
		camera.rotate(0.f, -speed * 1.5f, 0.f);
	}

    void turn_up(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		scene::Camera& camera = app->get_scene().get_camera();
		camera.rotate(speed * 1.5f, 0.f, 0.f);
	}

    void turn_down(bool /*just_activated*/, int /*data*/, float speed)
	{
		auto& game_camera = game::get_camera();

		if (game_camera.is_locked())
		{
			return;
		}

		scene::Camera& camera = app->get_scene().get_camera();
		camera.rotate(-speed * 1.5f, 0.f, 0.f);
	}

	void lock_camera(bool /*just_activated*/, int /*data*/, float /*speed*/)
	{
		game::get_camera().set_locked(true);

		app->get_client().show_system_cursor(true);
	}

	void unlock_camera()
	{
		game::get_camera().set_locked(false);

		app->get_client().show_system_cursor(false);
	}
}
