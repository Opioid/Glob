#include "Camera.hpp"

namespace game
{

Camera::Camera(float speed) : locked_(false), speed_(speed)
{}

bool Camera::is_locked() const
{
	return locked_;
}

void Camera::set_locked(bool locked)
{
	locked_ = locked;
}

float Camera::speed() const
{
	return speed_;
}

}
