//
//  Scene8.cpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/18.
//

#include "Scene8.hpp"
#include "HumanDetector.hpp"
#include "Macro.h"

/* -------------------------------------------------------------
 コンストラクタ
 ------------------------------------------------------------- */
Scene8::Scene8(ofxKinect *kinect) : SceneBase(kinect)
{
	this->sceneNum = 8;
}

/* -------------------------------------------------------------
 デストラクタ
 ------------------------------------------------------------- */
Scene8::~Scene8()
{
}

/* -------------------------------------------------------------
 更新処理
 ------------------------------------------------------------- */
void Scene8::update()
{
	SceneBase::update();
}

/* -------------------------------------------------------------
 描画処理
 ------------------------------------------------------------- */
void Scene8::draw()
{
	ofSetColor(0, 0, 0, 10);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

//	ofSetColor(255, 0, 0);
//	this->depthImg.draw(0, 0);
	
	HumanDetector *detector = new HumanDetector(this->depthImg);
	vector<ofxCvBlob> blobs = detector->getHumanImage();
	
	if (blobs.size() > 0)
	{
		ofxCvBlob blob = this->getLeftBlob(blobs);
		
		ofFill();
		ofBeginShape();
		double x = blob.centroid.x;
		SceneBase::ofSetHSVColor(x / ofGetWindowWidth() * 360, 100, 100);
		
		for (int i = 0; i < blob.pts.size(); i++)
		{
			double x = blob.pts[i].x;
			double y = blob.pts[i].y;
			
			ofVertex(x, y);
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


