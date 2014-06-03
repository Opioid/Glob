#include "Particle_fountain.hpp"
#include "Scene/Particles/Particle_effect.hpp"
#include "Scene/Material.hpp"

namespace scene
{

bool Particle_fountain_factory::init_particle_effect(Particle_effect& effect)
{
	effect.reserve(1);

	Particle_system* system = new Particle_fountain_system;

	effect.set_system(0, system);

	return true;
}

void Particle_fountain_factory::Particle_fountain_system::on_tick(float time_slice)
{

}

}
