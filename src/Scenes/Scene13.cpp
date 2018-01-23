//
//  Scene13.cpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#include "Scene13.hpp"
#include "HumanDetector.hpp"
#include "Macro.h"

/* -------------------------------------------------------------
 コンストラクタ
 ------------------------------------------------------------- */
Scene13::Scene13(ofxKinect *kinect) : SceneBase(kinect)
{
	this->sceneNum = 13;
}

/* -------------------------------------------------------------
 デストラクタ
 ------------------------------------------------------------- */
Scene13::~Scene13()
{
}

/* -------------------------------------------------------------
 更新処理
 ------------------------------------------------------------- */
void Scene13::update()
{
	SceneBase::update();
}

/* -------------------------------------------------------------
 描画処理
 ------------------------------------------------------------- */
void Scene13::draw()
{
	ofSetColor(0, 0, 0);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	HumanDetector *detector = new HumanDetector(this->depthImg);
	vector<ofxCvBlob> blobs = detector->getHumanImage();
	
	if (blobs.size() > 0)
	{
		ofxCvBlob blob = this->getLeftBlob(blobs);
		
		ofFill();
		ofSetColor(255, 255, 255);
		ofBeginShape();

		for (int i = 0; i < blob.pts.size(); i++)
		{
			double x = blob.pts[i].x;
			double y = blob.pts[i].y;
			
			ofVertex(x, y);
		}
		
		ofEndShape();
	}
	
	SAFE_DELETE(detector);
}
