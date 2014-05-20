#pragma once

#include "Scene/Complex/Complex.hpp"

namespace scene
{

class Actor;

class Interpolation_test : public Complex
{

public:

	Interpolation_test();

	bool init(Scene& scene, Resource_manager& resource_manager);

	void on_tick();

private:

	Actor* m_actor_a;
	Actor* m_actor_b;

	float m_angle;
};


class Interpolation_test_factory : public Complex_factory
{

public:

	Complex* create_complex();
};

}
