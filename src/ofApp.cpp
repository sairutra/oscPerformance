#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscReceiveExample");
	ofSetFrameRate(60); // run at 60 fps
	ofSetVerticalSync(true);

	// listen on the given port
	ofLog() << "listening for osc messages on port " << PORT;
	receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

	// check for waiting messages
	while(receiver.hasWaitingMessages()){

		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		// check for mouse moved message
		if(m.getAddress() == "/vsynth")
		{
			// if (m.getArgType() == OFXOSC_TYPE_FLOAT)
			// 	ofLog() << "received float";
			// else if (m.getArgType() == OFXOSC_TYPE_INT32)
			// 	ofLog() << "received int";
			ofLog() << "received message";
			for(size_t i = 0; i < m.getNumArgs(); i++)
			{
				// display the argument - make sure we get the right type
				if(m.getArgType(i) == OFXOSC_TYPE_INT32){
					ofLog() << "received int";
					// ofLog() << "received value(int): " << ofToString(m.getArgAsInt32(i)) << std::endl;
				}
				else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
					oscValue = m.getArgAsFloat(i);
					ofLog() << "received value(float): " << oscValue;
				}
				else {
					ofLog() << "received something";
				}
			}
		}


		// check for an image being sent
		// note: the size of the image depends greatly on your network buffer
		// sizes, if an image is too big the message won't come through
		else if(m.getAddress() == "/image"){
			ofBuffer buffer = m.getArgAsBlob(0);
			receivedImage.load(buffer);
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(0, 0);

	// if image exists, draw it
	if(receivedImage.getWidth() > 0){
		ofSetColor(255);
		receivedImage.draw(ofGetWidth()/2 - receivedImage.getWidth()/2,
		                   ofGetHeight()/2 - receivedImage.getHeight()/2);
	}
	
	ofColor color;
	float output = ofMap(oscValue, 0, 1, 0, 255);
	color.setHsb(0,0,output);
	ofSetColor(color);
	ofDrawCircle(WIDTH/2, HEIGTH/2, 10);
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
