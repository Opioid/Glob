#include "Rendering.hpp"
#include "Application/Application.hpp"
#include "Rendering/Printer.hpp"

namespace rendering
{

bool show_fps = false;

bool on_pre_init(Application& app)
{
	return app.get_script_tool().get_engine().register_variable("bool show_fps", &show_fps);
}

bool on_post_init(Application& /*app*/)
{
	return true;
}

void render_gui(Application& app, Printer& printer)
{
	if (show_fps)
	{
		printer.set_color(color4::white);
		printer.set_font("seguisb", 28);

		printer.set_position(float2(0.f, 0.f));
		printer.print("Fps: " + std::to_string(app.get_fps_counter().get_fps()));
	}
}

}
