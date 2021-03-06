#include "ofApp.h"

#include <iostream>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(FPS);
  ofSetWindowShape(1024, 768*2);
  ofSetWindowPosition(1921, 0);
  
  // PM
  pmx = PMx::getInstance();
  pmx->setup();
  
  manager.init();
}

//----------------------------------f----------------------------
void ofApp::update() {
  manager.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  manager.draw();
}

void ofApp::exit() {
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 'q') {
    ofExit();
  }
  pmx->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  manager.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofxOscMessage msg){
  
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
  
}
