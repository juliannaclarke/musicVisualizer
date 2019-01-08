#pragma once

#include "ofMain.h"
#include "AudioAnalyser.h"
#include <vector>
#include "Particle.h"
#include "Snowflake.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofColor winterBG;
		ofColor springBG;

		void keyPressed(int key);
		void generateSnow();
		void stopSnow();

		ofImage strawberry;

		void drawSun();
		void drawStrawberries();
		void removeStrawberries();

		ofTrueTypeFont m_font;
		ofFmodSoundPlayer m_player;
		ofSoundPlayer m_playerOF;
		AudioAnalyser m_audioAnalyser;

		bool debug;
		bool paused;
		bool isSnowing;

		float vocals;
		float drum;
		float chorus;
		float chorus2;
		float volume;

		vector<Snowflake> snow;
		vector<ofVec2f> strawberries;

		float sunSize;
		
};
