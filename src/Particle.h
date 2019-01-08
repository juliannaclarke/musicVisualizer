#pragma once
#include "ofMain.h"
#include <time.h>

class Particle: public ofBaseApp
{
public:
	Particle();
	~Particle();

	ofVec2f m_pos;
	ofVec2f m_velocity;
	ofColor m_colour; // 244, 20, 49
	ofVec2f m_size;

	void setup();
	void update();
	void draw();
};

