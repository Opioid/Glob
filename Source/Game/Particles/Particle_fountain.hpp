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

		Particle_fountain_system(uint32_t num_particles);
		~Particle_fountain_system();

	private:

		virtual void private_on_tick(const Particle_effect& effect, float time_slice);

		struct Particle_properties
		{
			float3 direction;
			float  age;
		};

		Particle_properties* properties_;

		const float max_age_;
	};
};

}
