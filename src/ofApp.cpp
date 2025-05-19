#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowTitle("oscReceiveExample");
	ofSetFrameRate(60);
	ofSetVerticalSync(false);

	ofLog() << "listening for osc messages on port " << PORT;
	ofLog() << ofGetFrameRate();
	receiver.setup(PORT);
    sender.setup("127.0.0.1", 57120);
    message.setAddress("/getamp");
}

//--------------------------------------------------------------
void ofApp::update()
{
    sender.sendMessage(message, true);
	while(receiver.hasWaitingMessages())
	{
		ofxOscMessage m;
		receiver.getNextMessage(m);
		std::string address = m.getAddress();

		if(address == "/amp1")
		{
			ofLog() << "received message";
			for(size_t i = 0; i < m.getNumArgs(); i++)
			{
				if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
				{
					oscValue = m.getArgAsFloat(i);
					ofLog() << "received value(float): " << oscValue;
				}
				else
					ofLog() << "received something";
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw()
{
	ofColor color;

	float output = ofMap(oscValue, 0, 1, 0, 255);
	color.setHsb(0,0,output);
	ofBackground(color);

	// ofSetColor(color);
	// ofDrawCircle(xPosition, WIDTH/2, 10);
	// xPosition += 100;
	// // yPosition += 100;
	// if (xPosition > ofGetWidth())
	// 	xPosition =  static_cast<int>(xPosition) % ofGetWidth();
	// if (yPosition > ofGetHeight())
	// 	yPosition =  static_cast<int>(yPosition) % ofGetHeight();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
