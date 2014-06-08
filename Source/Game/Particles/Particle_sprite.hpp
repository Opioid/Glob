#pragma once

#include "Scene/Particles/Particle_effect_factory.hpp"
#include "Scene/Particles/Particle_system.hpp"

namespace scene
{

class Particle_sprite_factory : public Particle_effect_factory
{

public:

	virtual bool init_particle_effect(Particle_effect& effect);

private:

	class Particle_sprite_system : public Particle_system
	{

	public:

		Particle_sprite_system(uint32_t num_particles);
		~Particle_sprite_system();

	private:

		virtual void private_on_tick(float time_slice);

		float index_;
	};
};

}
