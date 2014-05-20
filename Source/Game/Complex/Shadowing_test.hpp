#pragma once

#include "Scene/Complex/Complex.hpp"

namespace scene
{

class Shadowing_test : public Complex
{

public:

	bool init(Scene& scene, Resource_manager& resource_manager);
};


class Shadowing_test_factory : public Complex_factory
{

public:

	Complex* create_complex();
};

}
