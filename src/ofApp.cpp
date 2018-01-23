#include "ofApp.h"

#include "Scene8.hpp"
#include "Scene13.hpp"
#include "Scene15.hpp"

/* -------------------------------------------------------------
 初期化
------------------------------------------------------------- */
void ofApp::setup()
{
	ofSetWindowShape(640, 480);
	ofSetFrameRate(60);
//	ofBackground(0, 0, 0);
	ofSetBackgroundAuto(false);

	this->currentSceneIdx = 0;
	
	this->kinect = new ofxKinect();
	
	// Kinect初期化
	this->kinect->init();
	this->kinect->open();

	this->kinectTiltAngle = 0;
	this->kinect->setCameraTiltAngle(this->kinectTiltAngle);
	
	// シーン初期化
	this->scenes.push_back(new Scene8(this->kinect));			// シーン8
	this->scenes.push_back(new Scene13(this->kinect));			// シーン13
	this->scenes.push_back(new Scene15(this->kinect));			// シーン15

}

/* -------------------------------------------------------------
 更新処理
 ------------------------------------------------------------- */
void ofApp::update()
{
	this->kinect->update();
	(this->scenes[this->currentSceneIdx])->update();
}

/* -------------------------------------------------------------
 描画処理
 ------------------------------------------------------------- */
void ofApp::draw()
{
//	this->kinect->drawDepth(0.0f, 0.0f, ofGetWindowWidth(), ofGetWindowHeight());

	SceneBase *scene = this->scenes[this->currentSceneIdx];
	
	scene->draw();
	
#ifdef DEBUG_MODE
	stringstream msg;
	msg << "FPS: " << ofToString(ofGetFrameRate()) << "\n";
	msg << "Near: " << ofToString(scene->near) << "\n";
	msg << "Far: " << ofToString(scene->far) << "\n";
	msg << "Angle: " << ofToString(this->kinectTiltAngle) << "\n";
	msg << "SceneNum: " << ofToString(scene->sceneNum) << "\n";
	
	ofSetColor(0, 255, 0);
	ofDrawBitmapString(msg.str(), 0, 20);
#endif
	
	if (this->isBackScreen)
	{
		ofFill();
		ofSetColor(0, 0, 0);
		ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	}
	
	this->syphon.publishScreen();
}

/* -------------------------------------------------------------
 終了処理
 ------------------------------------------------------------- */
void ofApp::exit()
{
	vector<SceneBase *>::iterator it = this->scenes.begin();
	while(it != this->scenes.end())
	{
		delete (*it);
		it++;
	}
	
	this->kinect->close();
	this->kinect->clear();
	
	delete this->kinect;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	// 上キー
	if (key == 357)
	{
		(this->scenes[this->currentSceneIdx])->far += 100;
	}
	// 下キー
	else if (key == 359)
	{
		(this->scenes[this->currentSceneIdx])->far -= 100;
	}
	// uキー
	else if (key == 117)
	{
		if (this->kinectTiltAngle + 1 <= 30)
		{
			this->kinectTiltAngle++;
			this->kinect->setCameraTiltAngle(this->kinectTiltAngle);
		}
	}
	// dキー
	else if (key == 100)
	{
		if (this->kinectTiltAngle - 1 >= -30)
		{
			this->kinectTiltAngle--;
			this->kinect->setCameraTiltAngle(this->kinectTiltAngle);
		}
	}
	// 右キー
	else if (key == 358)
	{
		if (this->currentSceneIdx + 1 <= this->scenes.size()-1)
		{
			this->currentSceneIdx++;
		}
	}
	// 左キー
	else if (key == 356)
	{
		if (this->currentSceneIdx - 1 >= 0)
		{
			this->currentSceneIdx--;
		}
	}
	// 「1」キー
	else if (key == 49)
	{
		this->isBackScreen = true;
	}
	// Enterキー
	else if (key == 13)
	{
		this->isBackScreen = false;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
