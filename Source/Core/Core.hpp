#pragma once

#include "Application/Application.hpp"

namespace core
{

class Glob_app : public Application
{

public:

	virtual ~Glob_app();

protected:

	virtual bool on_pre_init();
	virtual bool on_post_init();

	virtual void on_scene_loaded();

	virtual void on_tick(float time_slice);

	virtual void on_render_gui(rendering::Printer& printer);
};

void run();

}
