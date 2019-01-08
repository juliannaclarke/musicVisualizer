#pragma once
#include "ofMain.h"
#include "Particle.h"

class Snowflake: public Particle
{
public:
	Snowflake();
	Snowflake(ofVec2f pos, ofVec2f velocity);
	~Snowflake();

	bool changeVelocity;

	void update();
	void draw();

	void setVelocity(float velocityX, float velocityY);


};

