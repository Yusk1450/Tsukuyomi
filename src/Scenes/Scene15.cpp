//
//  Scene15.cpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#include "Scene15.hpp"
#include "HumanDetector.hpp"
#include "Macro.h"

/* -------------------------------------------------------------
 コンストラクタ
 ------------------------------------------------------------- */
Scene15::Scene15(ofxKinect *kinect) : SceneBase(kinect)
{
	this->sceneNum = 15;
}

/* -------------------------------------------------------------
 デストラクタ
 ------------------------------------------------------------- */
Scene15::~Scene15()
{
}

/* -------------------------------------------------------------
 更新処理
 ------------------------------------------------------------- */
void Scene15::update()
{
	SceneBase::update();
}

/* -------------------------------------------------------------
 描画処理
 ------------------------------------------------------------- */
void Scene15::draw()
{
	ofSetColor(0, 0, 0, 10);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	
	
	HumanDetector *detector = new HumanDetector(this->depthImg);
	vector<ofxCvBlob> blobs = detector->getHumanImage();
	
	ofFill();
	ofSetColor(255, 255, 255);
	for (int i = 0; i < blobs.size(); i++)
	{
		ofBeginShape();
		
		for (int j = 0; j < blobs[i].pts.size(); j++)
		{
			double x = blobs[i].pts[j].x;
			double y = blobs[i].pts[j].y;
			
			ofVertex(x, y);
			//			ofNoFill();
			//			ofDrawCircle(x, y, 1);
		}
		
		ofEndShape();
	}
	
	//	for (int i = 0; i < blobs.size(); i++)
	//	{
	//		double x = blobs[i].centroid.x;
	//		double y = blobs[i].centroid.y;
	//
	//		ofSetColor(255, 0, 0, 200);
	//		ofDrawCircle(x, y, 5);
	//	}
	
	SAFE_DELETE(detector);
}
