#pragma once


#include "Scene/Complex/Complex.hpp"

namespace scene
{

class Static_stress_test : public Complex
{
public:

	bool init(Scene& scene, Resource_manager& resource_manager);
};


class Static_stress_test_factory : public Complex_factory
{
public:

	Complex* create_complex();
};

}
