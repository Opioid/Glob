#include "Particles.hpp"
#include "Particle_fountain.hpp"
#include "Application/Application.hpp"
#include "Scene/Scene.hpp"

namespace game
{

scene::Particle_fountain_factory particle_fountain_factory;

bool init_particles(Application& application)
{
	auto& particle_scene = application.scene().particle_scene();

	particle_scene.register_factory(&particle_fountain_factory, "Particle_fountain");

	return true;
}

}
