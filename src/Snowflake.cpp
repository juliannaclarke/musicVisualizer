#include "Snowflake.h"

Snowflake::Snowflake()
{
}

Snowflake::Snowflake(ofVec2f pos, ofVec2f velocity)
{
	m_pos = pos;
	m_velocity = velocity;
	m_colour = (255);
}

Snowflake::~Snowflake()
{
}

void Snowflake::update()
{
	m_pos.x = m_pos.x + m_velocity.x;
	m_pos.y = m_pos.y + m_velocity.y;

	changeVelocity = (rand() % 100) < 1;
	if (changeVelocity) {
		m_velocity.set((rand() % 5) - 2, (rand() % 2 + 1));
	}
}

void Snowflake::draw()
{
	ofSetColor(m_colour);
	ofDrawCircle(m_pos.x, m_pos.y, 3);
}

void Snowflake::setVelocity(float velocityX, float velocityY)
{
	m_velocity.set(velocityX, velocityY);
}
