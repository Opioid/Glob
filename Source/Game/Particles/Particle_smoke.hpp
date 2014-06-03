#pragma once

#include "Scene/Particles/Particle_effect_factory.hpp"
#include "Scene/Particles/Particle_system.hpp"

namespace scene
{

class Particle_smoke_factory : public Particle_effect_factory
{

public:

	virtual bool init_particle_effect(Particle_effect& effect);

private:

	class Particle_smoke_system : public Particle_system
	{

	public:

		Particle_smoke_system(uint32_t num_particles);
		~Particle_smoke_system();

	private:

		virtual void private_on_tick(const Particle_effect& effect, float time_slice);

		struct Particle_properties
		{
			float3 direction;
			float  age;
			float  birth_age;
		};

		Particle_properties* properties_;

		const float max_age_;
	};
};

}
