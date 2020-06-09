#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWindowTitle("FoxDot - oscReceiveExample");
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofSetCircleResolution(50);

  receiver.setup(PORT); // listen on the given port
}

//--------------------------------------------------------------
void ofApp::update(){
  // receive FoxDot OSC messages 
  // and store the data
  while(receiver.hasWaitingMessages()){
    ofxOscMessage m;
    receiver.getNextMessage(m);
    foxdot.update(m);
  }
}


//--------------------------------------------------------------
void ofApp::draw(){
  ofBackgroundGradient(100, 0);

  // grid example -------------------------------------
  if(foxdot.sds["jbass"]["active"]){
    ofPushMatrix();
    ofPushStyle();
      int rows = 8;
      int cols = 8;
      ofTranslate(ofGetWidth()/(rows*2),ofGetHeight()/(cols*2));
      for(int i =0;i< rows;i++){
        for(int j =0;j< cols;j++){
          ofPushMatrix();
            ofTranslate((ofGetWidth()/rows)*i,(ofGetHeight()/cols)*j);
            ofSetColor(255,50);
            ofDrawCircle(0,0,foxdot.sds["jbass"]["midinote"]*1.025);
          ofPopMatrix();
        }
      }
    ofPopStyle();
    ofPopMatrix();
  }

  // grid example -------------------------------------
  if(foxdot.sds["play2"]["active"]){
    ofPushMatrix();
    ofPushStyle();
      int rows = 8;
      int cols = 8;
      ofTranslate(ofGetWidth()/(rows*2),ofGetHeight()/(cols*2));
      for(int i =0;i< rows;i++){
        for(int j =0;j< cols;j++){
          ofPushMatrix();
            ofTranslate((ofGetWidth()/rows)*i,(ofGetHeight()/cols)*j);
            ofSetColor(255,100);
            /*
            if(i % 2 == 0){
              ofRotate(foxdot.sds["play2"]["count"]*2);
            }else{
              ofRotate(foxdot.sds["play2"]["count"]*-2);
            }
            if(i % 2 == 0){
              ofDrawCircle(0,-20,10);
              ofScale(1.25,1.25,0);
              ofDrawCircle(0,-20,20);
            }
            ofDrawCircle(0,20,10);
            */
            
            ofRotate(foxdot.sds["play2"]["count"]);
            ofDrawCircle(0,20,10);
          ofPopMatrix();
        }
      }
    ofPopStyle();
    ofPopMatrix();
  }

  // grid example -------------------------------------
  if(foxdot.sds["space"]["active"]){
    ofPushMatrix();
    ofPushStyle();
      ofSetColor(255,200);
      ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
      ofTranslate(0,-20*10);
      ofTranslate(foxdot.sds["space"]["freq"]*-0.5,0);
      for(int l = 0; l < 21; l++){
        ofSetLineWidth(foxdot.sds["space"]["midinote"]/10);
        ofDrawLine(0,l*20,foxdot.sds["space"]["freq"],l*20);
      }
    ofPopStyle();
    ofPopMatrix();
  }

  string buf = "listening for osc messages on port " + ofToString(PORT);
  ofDrawBitmapStringHighlight(buf, 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
