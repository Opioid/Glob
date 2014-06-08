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

	Particle_system* system = new Particle_smoke_system(64);

	effect.set_system(0, system);

	return true;
}

Particle_smoke_factory::Particle_smoke_system::Particle_smoke_system(uint32_t num_particles) :
	Particle_system(num_particles),
	properties_(new Particle_properties[num_particles]),
	max_age_(5.f)
{
	Vertex* vertices = this->vertices();

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

void Particle_smoke_factory::Particle_smoke_system::on_update(float /*frame_time*/, float speed)
{
	Vertex* vertices = this->vertices();

	const float3 position = parent()->world_position();

	for (uint32_t i = 0; i < num_particles(); ++i)
	{
		if (properties_[i].age >= max_age_)
		{
			vertices[i].position = position + 0.15f * math::random_disk();

			float scale = math::random(0.15f, 0.3f);
			vertices[i].scale = float2(scale, scale);
			vertices[i].angle = math::random(0.f, math::pi_mul_2);

			properties_[i].birth_age = math::random(0.f, 0.35f * max_age_);
			properties_[i].age = properties_[i].birth_age;
			properties_[i].direction = 0.25f * float3(0.f, 1.f, 0.f);

			properties_[i].direction.x += math::random(-1.f, 1.f) * 0.1f;
			properties_[i].direction.y += math::random(-1.f, 1.f) * 0.1f;
			properties_[i].direction.z += math::random(-1.f, 1.f) * 0.1f;
		}

		vertices[i].position += speed * (properties_[i].direction + float3(0.f, 0.8f, 0.f));
		vertices[i].scale	 += speed * float2(0.075f, 0.075);
		vertices[i].angle	 += speed * 0.3f;

		float ratio = (properties_[i].age - properties_[i].birth_age) / (max_age_ - properties_[i].birth_age);
		vertices[i].alpha = std::sin(math::pi * ratio) * 0.6f;

		properties_[i].age += speed;
	}
}

}
