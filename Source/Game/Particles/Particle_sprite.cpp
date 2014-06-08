#include "Particle_sprite.hpp"
#include "Scene/Particles/Particle_effect.hpp"
#include "Scene/Material.hpp"
#include "Rendering/Resource_view.hpp"
#include "Math/Math.hpp"
#include "Math/Vector.inl"

namespace scene
{

bool Particle_sprite_factory::init_particle_effect(Particle_effect& effect)
{
	effect.reserve(1);

	Particle_system* system = new Particle_sprite_system(1);

	effect.set_system(0, system);

	return true;
}

Particle_sprite_factory::Particle_sprite_system::Particle_sprite_system(uint32_t num_particles) :
	Particle_system(num_particles), index_(0.f)
{}

Particle_sprite_factory::Particle_sprite_system::~Particle_sprite_system()
{}

void Particle_sprite_factory::Particle_sprite_system::on_update(float /*frame_time*/, float speed)
{
	Vertex& vertex = vertices()[0];

	vertex.position = parent_->world_position();
	vertex.scale = float2(0.4f, 0.4f);
	vertex.angle = 0.f;

	vertex.index = index_;

	if (material_->is_array())
	{
		index_ += 16.f * speed;

		float max_index = static_cast<float>(material_->textures()[0]->description().num_layers);

		if (index_ >= max_index)
		{
			index_ = 0.f;
		}
	}

	vertex.alpha = 1.f;
}

}
