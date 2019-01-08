#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetWindowShape(1280, 900);
	srand(time(NULL));
	debug = false;
	paused = false;

	winterBG = ofColor(230, 220, 220);
	springBG = ofColor(51, 204, 255);

	m_font.load("fonts/OratorStd.otf", 12, true);
	m_player.load("audio/whiteWinterHymnal.mp3");
	m_player.setLoop(true);
	m_player.play();

	m_audioAnalyser.init(&m_player, 15);

	strawberry.load("strawberry.png");
	strawberry.setAnchorPoint(7, 10);

	isSnowing = true;

	ofSetBackgroundColor(winterBG);
}

//--------------------------------------------------------------
void ofApp::update(){

	m_audioAnalyser.update();
	volume = m_audioAnalyser.getMixLevel();

	vocals = m_audioAnalyser.getLinearAverage(4);
	chorus = m_audioAnalyser.getLinearAverage(14);
	chorus2 = m_audioAnalyser.getLinearAverage(11);
	drum = m_audioAnalyser.getLinearAverage(1);

	if (paused) {
		isSnowing = true;
	}
	else if (m_player.getPositionMS() / 1000.0f >= 40.5 && m_player.getPositionMS() / 1000.0f <= 121.00) {
		isSnowing = false;
	}
	else if (volume <= 0.21) {
		isSnowing = true;
	}
	else {
		isSnowing = true;
	}

	if (isSnowing) {
		generateSnow();

		ofSetBackgroundColor(winterBG);
		removeStrawberries();

		
	}
	else {
		stopSnow();

		ofSetBackgroundColor(springBG);
	}

	for (auto i = snow.begin(); i != snow.end();) {

		if (m_player.getPositionMS() / 1000.0f > 121.0) {
			(*i).m_velocity.y = ofMap(vocals, 10.0, 70.0, 1, 5, true);
		}
		(*i).update();

		if ((*i).m_pos.x < 0 - 5 || (*i).m_pos.x > ofGetScreenWidth() + 5 || (*i).m_pos.y > ofGetScreenHeight() + 5) {
			i = snow.erase(i);
		}
		else {
			i++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0);
	m_font.drawString("Press 'd' to toggle the song information", 850, 50);
	m_font.drawString("Press SPACE to pause/play", 850, 70);

	float songTimeSeconds = m_player.getPositionMS() / 1000.0f;
	m_font.drawString("Song time: " + ofToString(songTimeSeconds), 40, 50);

	if (debug == true) {
		ofSetColor(0);
		m_font.drawString("Volume Level", 140, 150);

		ofDrawCircle(100, 100, m_audioAnalyser.getLeftLevel()  * 100.0f);
		ofDrawCircle(200, 100, m_audioAnalyser.getRightLevel() * 100.0f);
		ofDrawCircle(300, 100, m_audioAnalyser.getMixLevel()   * 100.0f);

		m_font.drawString("Left", 80, 200);
		m_font.drawString("Right", 180, 200);
		m_font.drawString("Mix", 290, 200);

		m_audioAnalyser.drawWaveform(40, 300, 1200, 90);
		m_audioAnalyser.drawSpectrum(40, 460, 1200, 128);

		m_audioAnalyser.drawLinearAverages(40, 650, 1200, 128);
	}

	drawSun();
	drawStrawberries();
	
	for (int i = 0; i < snow.size(); i++) {
		snow[i].draw();
	}

	
}

//--------------------------------------------------------------  
void ofApp::keyPressed(int key){
	if (key == 'd' || key == 'D') {
		if (debug) {
			debug = false;
		}
		else {
			debug = true;
		}
	}

	if (key == 32) {
		if (!paused) {
			m_player.setPaused(true);
			paused = true;
		}
		else {
			m_player.setPaused(false);
			paused = false;
		}
	}

	if (key == 'n') {
		m_player.setPositionMS(m_player.getPositionMS() + 15000);
	}

}



//-------------------------------------------------------------
void ofApp::generateSnow() {

	if ((rand() % 100) < 15) {

		ofVec2f pos((rand() % 1281), 0);
		ofVec2f velocity((rand() % 5) - 2, (rand() % 2 + 1));

		snow.push_back(Snowflake(pos, velocity));
	}
}

void ofApp::stopSnow()
{

	for (int i = 0; i < snow.size(); i++) {
		snow[i].setVelocity(-6, 2);
	}
}

void ofApp::drawSun() {

	sunSize = ofMap(chorus, 20.0f, 50.0f, 50.0f, 70.0f, true);

	for (int i = 0; i < 3; i++) {
		if (isSnowing) {
			ofSetColor(255, 255, 255, 255 - 90 * i);
		}
		else {
			ofSetColor(255, 215, 25, 255 - 90 * i);
		}
		ofDrawCircle(950, 150, sunSize + i * 10);
	}

	if (m_player.getPositionMS()/1000.0f >= 18) {
		sunSize = ofMap(chorus2, 10.0f, 30.0f, 50.0f, 70.0f, true);
	}
}


void ofApp::drawStrawberries()
{
	if (drum > 200) {
		strawberries.push_back(ofVec2f(rand() % 1280, rand() % 800 + 500));
	}
	for (int i = 0; i < strawberries.size(); i++) {
		ofSetColor(0, 98, 51);
		ofDrawLine(strawberries[i].x, strawberries[i].y, strawberries[i].x, ofGetWindowHeight());

		ofSetColor(255);
		strawberry.draw(strawberries[i].x, strawberries[i].y, 14, 20);
		
	}
}

void ofApp::removeStrawberries()
{
	if (strawberries.size() != 0) {
		strawberries.pop_back();
	}
}
