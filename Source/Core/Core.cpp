#include "Core.hpp"
#include "Rendering/Rendering.hpp"
#include "Game/Game.hpp"
#include "../Controls/Controls.hpp"
#include "Math/Vector.inl"

namespace core
{

Glob_app::~Glob_app()
{}

bool Glob_app::on_pre_init()
{
	if (!rendering::on_pre_init(*this))
	{
		return false;
	}

	if (!game::on_pre_init(*this))
	{
		return false;
	}

	return true;
}

bool Glob_app::on_post_init()
{
	if (!rendering::on_post_init(*this))
	{
		return false;
	}

	if (!game::on_post_init(*this))
	{
		return false;
	}

	if (!controls::init(this))
	{
		return false;
	}

	return true;
}

void Glob_app::on_scene_loaded()
{
	game::on_load_scene(*this);
}

void Glob_app::on_tick(float time_slice)
{
	game::update(*this, time_slice);
}

void Glob_app::on_render_gui(rendering::Printer& printer)
{
	rendering::render_gui(*this, printer);
}

void run()
{
	Glob_app app;

	if (!app.run("Glob", uint2(1280, 720), false))
	{
	//	platform::message_box("Sorry! :(\nFailed to initialize. Try the log for hints.", "Glob");
	}
}
}
