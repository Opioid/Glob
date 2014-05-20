#pragma once

#include "Scene/Complex/Complex.hpp"

namespace scene
{

class Material_test : public Complex
{

public:

	bool init(Scene& scene, Resource_manager& resource_manager);
};


class Material_test_factory : public Complex_factory
{

public:

	Complex* create_complex();
};

}
