#pragma once

#include "Scene/Particles/Particle_effect_factory.hpp"

namespace scene
{

class Particle_fountain_factory : public Particle_effect_factory
{

public:

	virtual bool init_particle_effect(Particle_effect& effect);
};

}
