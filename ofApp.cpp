#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239, 32);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	float size = 1;
	for (float x = 80; x <= ofGetWidth() - 80; x += size) {

		for (float y = 80; y <= ofGetHeight() - 80; y += size) {

			float deg = ofMap(ofNoise(x * 0.008, y * 0.008, ofGetFrameNum() * 0.03), 0, 1, -360, 360);
			this->mesh.addVertex(glm::vec3(x + size * 3 * cos(deg * DEG_TO_RAD), y + size * 3 * sin(deg * DEG_TO_RAD), ofMap(abs(deg), 0, 360, 0, 150)));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofTranslate(ofGetWindowSize() * -0.5);

	this->mesh.drawVertices();

	this->cam.end();
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}