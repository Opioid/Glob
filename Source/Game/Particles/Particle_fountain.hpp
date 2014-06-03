#pragma once

#include "Scene/Particles/Particle_effect_factory.hpp"
#include "Scene/Particles/Particle_system.hpp"

namespace scene
{

class Particle_fountain_factory : public Particle_effect_factory
{

public:

	virtual bool init_particle_effect(Particle_effect& effect);

private:

	class Particle_fountain_system : public Particle_system
	{

	public:

		virtual void on_tick(float time_slice);
	};
};

}
