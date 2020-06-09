#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

class FoxDot{
  
  public:
    FoxDot(); // constructor: initializes the object
    void setup();
    void update(ofxOscMessage m);
    void draw();

    int countNum;
    float dur;
    vector<string> sdNames;
    vector<string> sdAttributes;
    map<string, map<string,float>> sds;
};
