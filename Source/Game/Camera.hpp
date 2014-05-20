#pragma once

namespace game
{

class Camera
{

public:

	Camera(float speed = 4.f);

	bool is_locked() const;
	void set_locked(bool locked);

	float get_speed() const;

private:

	bool locked_;

	float speed_;
};

}
