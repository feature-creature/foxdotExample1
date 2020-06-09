#include "FoxDot.h"

FoxDot::FoxDot(){
  sdNames = {
    "loop", "stretch", "play1", "play2", "audioin", 
    "noise", "dab", "varsaw", "lazer", "growl", 
    "bass", "dirt", "crunch", "rave", "scatter", 
    "charm", "bell", "gong", "soprano", "dub", 
    "viola", "scratch", "klank", "feel", "glass", 
    "soft", "quin", "pluck", "spark", "blip", 
    "ripple", "creep", "orient", "zap", "marimba", 
    "fuzz", "bug", "pulse", "saw", "snick", 
    "twang", "karp", "arpy", "nylon", "donk", 
    "squish", "swell", "razz", "sitar", "star", 
    "jbass", "sawbass", "prophet", "pads", "pasha", 
    "ambi", "space", "keys", "dbass", "sinepad"	
  };
  
  sdAttributes = {
    "active","count","countRef","countExp",
    "bus", "freq", "delay", "buf", 
    "sample", "fmod", "pan", "rate", "midinote", 
    "channel", "vib", "vibdepth", "slide", "slidedelay", 
    "slidefrom", "glide", "glidedelay", "bend", "benddelay", 
    "course", "striate", "pshift", "hpf", "hpr", 
    "lpf", "lpr", "swell", "bpf", "bpr", 
    "bpnoise", "chop", "tremolo", "beat_dur", "echo", 
    "echotime", "spin", "cut", "room", "mix", 
    "formant", "shape", "drive", "sus", "blur", 
    "amp", "amplify", "dur", "oct", "atk", 
    "decay", "rel", "root"
  };

  for(int i = 0; i < sdNames.size();i++){
    sds[sdNames[i]];
    for(int a = 0; a < sdAttributes.size();a++){
      sds[sdNames[i]][sdAttributes[a]]=0.0;
    }
  }

  countNum = 0;
  cout << "foxdot created via constructor" << endl;
}

//----------------------------------------------------
void FoxDot::setup(){

}

//----------------------------------------------------
void FoxDot::update(ofxOscMessage m){
  if(m.getAddress() == "/s_new" && 
      m.getArgAsString(0) != "makeSound" && 
      m.getArgAsString(0) != "startSound"
  ){

    // global variables 
    countNum = m.getArgAsInt(1);
    // TODO: TURN OFF SYNTHDEFS
    //if( dur > m.getArgAsFloat())dur = m.getArgAsFloat();

    // this synthdef
    string sd = m.getArgAsString(0);
    sds[sd]["count"]=m.getArgAsInt(1);
    sds[sd]["countRef"]=m.getArgAsInt(3);
    sds[sd][m.getArgAsString(4)]=m.getArgAsFloat(5);
    for(size_t i = 6; i < m.getNumArgs(); i = i+2){
      sds[sd][m.getArgAsString(i)]=m.getArgAsFloat(i+1);
    }
    sds[sd]["countExp"]=m.getArgAsInt(1)+m.getArgAsInt(2)+sds[sd]["sus"];

    // ------------------------------
    // begin logging ----------------------
    // ------------------------------
    string msgString;
    msgString = m.getAddress();
    msgString += ":";

    for(size_t i = 0; i < m.getNumArgs(); i++){
      msgString += " ";
      msgString += m.getArgTypeName(i);
      msgString += ":";

      if(m.getArgType(i) == OFXOSC_TYPE_INT32){
        msgString += ofToString(m.getArgAsInt32(i));
      }
      else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
        msgString += ofToString(m.getArgAsFloat(i));
      }
      else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
        msgString += m.getArgAsString(i);
      }else{
        msgString += "unhandled argument type " + m.getArgTypeName(i);
      }
    }
    
    cout << msgString << endl;
    cout << countNum << endl;
    cout << "---------"<< endl;
    // ------------------------------
    // end logging ----------------------
    // ------------------------------
  }

  // activate synthdefs ------------------------------------------------------
  for(int i = 0; i < sdNames.size();i++){
    sds[sdNames[i]]["active"] = countNum - sds[sdNames[i]]["countExp"] > 128 ? 0.0 : 1.0;
  }
}

//----------------------------------------------------
void FoxDot::draw(){

}
