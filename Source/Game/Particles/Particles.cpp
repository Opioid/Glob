#include "Particles.hpp"
#include "Particle_fountain.hpp"
#include "Particle_smoke.hpp"
#include "Particle_sprite.hpp"
#include "Application/Application.hpp"
#include "Scene/Scene.hpp"

namespace game
{

scene::Particle_fountain_factory particle_fountain_factory;
scene::Particle_smoke_factory particle_smoke_factory;
scene::Particle_sprite_factory particle_sprite_factory;

bool init_particles(Application& application)
{
	auto& particle_scene = application.scene().particle_scene();

	particle_scene.register_factory(&particle_fountain_factory, "Particle_fountain");

	particle_scene.register_factory(&particle_smoke_factory, "Particle_smoke");

	particle_scene.register_factory(&particle_sprite_factory, "Particle_sprite");

	return true;
}

}
