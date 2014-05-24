#pragma once

class Application;

namespace game
{

class Camera;

bool on_pre_init(Application &application);

bool on_post_init(Application &application);
	
void on_load_scene(Application &application);
	
void update(Application &application);

Camera& camera();

void toggle_flashlight(bool just_activated, int data, float speed);

}
