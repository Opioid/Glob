#include "Particle_fountain.hpp"
#include "Scene/Particles/Particle_effect.hpp"
#include "Scene/Material.hpp"
#include "Math/Math.hpp"
#include "Math/Vector.inl"

namespace scene
{

bool Particle_fountain_factory::init_particle_effect(Particle_effect& effect)
{
	effect.reserve(1);

	Particle_system* system = new Particle_fountain_system(256);

	effect.set_system(0, system);

	return true;
}

Particle_fountain_factory::Particle_fountain_system::Particle_fountain_system(uint32_t num_particles) :
	Particle_system(num_particles),
	properties_(new Particle_properties[num_particles]),
	max_age_(3.f)
{
	for (uint32_t i = 0; i < this->num_particles(); ++i)
	{
		properties_[i].age = max_age_;
	}
}

Particle_fountain_factory::Particle_fountain_system::~Particle_fountain_system()
{
	delete [] properties_;
}

void Particle_fountain_factory::Particle_fountain_system::private_on_tick(const Particle_effect& effect, float time_slice)
{
	Vertex* vertices = current_vertices();

	const float3 position = effect.world_position();

	for (uint32_t i = 0; i < num_particles(); ++i)
	{
		if (max_age_ <= properties_[i].age)
		{
			vertices[i].position = position;
			vertices[i].properties.x = math::random(0.025f, 0.05f);

			properties_[i].age = math::random(0.f, max_age_);
			properties_[i].direction = 0.1f * normalize(float3(math::random(-0.01f, 0.01f), 0.05f, math::random(-0.01f, 0.01f)));
		}

		properties_[i].direction -= time_slice * float3(0.f, 0.1f, 0.f);
		vertices[i].position += properties_[i].direction;

		properties_[i].age += time_slice;
	}
}

}
