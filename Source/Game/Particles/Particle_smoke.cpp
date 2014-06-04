#include "Particle_smoke.hpp"
#include "Scene/Particles/Particle_effect.hpp"
#include "Scene/Material.hpp"
#include "Math/Math.hpp"
#include "Math/Vector.inl"

namespace scene
{

bool Particle_smoke_factory::init_particle_effect(Particle_effect& effect)
{
	effect.reserve(1);

	Particle_system* system = new Particle_smoke_system(96);

	effect.set_system(0, system);

	return true;
}

Particle_smoke_factory::Particle_smoke_system::Particle_smoke_system(uint32_t num_particles) :
	Particle_system(num_particles),
	properties_(new Particle_properties[num_particles]),
	max_age_(5.f)
{
	Vertex* vertices = current_vertices();

	for (uint32_t i = 0; i < num_particles; ++i)
	{
		vertices[i].position = float3(10000.f, 10000.f, 10000.f);
		properties_[i].age = math::random(0.f, max_age_);
	}
}

Particle_smoke_factory::Particle_smoke_system::~Particle_smoke_system()
{
	delete [] properties_;
}

void Particle_smoke_factory::Particle_smoke_system::private_on_tick(float time_slice)
{
	Vertex* vertices = current_vertices();

	const float3 position = parent()->world_position();

	for (uint32_t i = 0; i < num_particles(); ++i)
	{
		if (properties_[i].age >= max_age_)
		{
			vertices[i].position = position + 0.2f * math::random_disk();
			vertices[i].properties.x = math::random(0.2f, 0.35f);
			vertices[i].properties.y = math::random(0.f, math::pi_mul_2);

			properties_[i].birth_age = math::random(0.f, 0.4f * max_age_);
			properties_[i].age = properties_[i].birth_age;
			properties_[i].direction = 0.25f * float3(0.f, 1.f, 0.f);

			properties_[i].direction.x += math::random(-1.f, 1.f) * 0.075f;
			properties_[i].direction.y += math::random(-1.f, 1.f) * 0.075f;
			properties_[i].direction.z += math::random(-1.f, 1.f) * 0.075f;
		}

		vertices[i].position     += time_slice * (properties_[i].direction + float3(0.f, 0.8f, 0.f));
		vertices[i].properties.x += time_slice * 0.075f;
		vertices[i].properties.y += time_slice * 0.3f;

		float ratio = (properties_[i].age - properties_[i].birth_age) / (max_age_ - properties_[i].birth_age);
		vertices[i].properties.z = std::sin(math::pi * ratio) * 0.6f;

		properties_[i].age += time_slice;
	}
}

}
