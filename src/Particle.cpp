#include "Particle.h"



Particle::Particle()
{
}


Particle::~Particle()
{
}

void Particle::setup()
{
}

void Particle::update()
{
	m_pos.x = m_pos.x + m_velocity.x;
	m_pos.y = m_pos.y + m_velocity.y;
}

void Particle::draw()
{
}
