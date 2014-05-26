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

	void on_tick(float time_slice);

private:

	Actor* actor_a_;
	Actor* actor_b_;

	float angle_;
};


class Interpolation_test_factory : public Complex_factory
{

public:

	Complex* create_complex();
};

}
