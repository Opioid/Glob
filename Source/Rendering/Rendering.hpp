#pragma once

class Application;

namespace rendering
{

class Printer;

bool on_pre_init(Application& app);
bool on_post_init(Application& app);

void render_gui(Application& app, Printer& printer);

}
