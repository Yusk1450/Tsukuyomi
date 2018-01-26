//
//  Scene23.cpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#include "Scene23.hpp"
#include "HumanDetector.hpp"
#include "Macro.h"

/* -------------------------------------------------------------
 コンストラクタ
 ------------------------------------------------------------- */
Scene23::Scene23(ofxKinect *kinect) : SceneBase(kinect)
{
	this->sceneNum = 23;
	
	this->isSplit = false;
	this->moveDeltaX = 0.0;
	this->cnt = 0.0;
}

/* -------------------------------------------------------------
 デストラクタ
 ------------------------------------------------------------- */
Scene23::~Scene23()
{
}

/* -------------------------------------------------------------
 更新処理
 ------------------------------------------------------------- */
void Scene23::update()
{
	SceneBase::update();
	
	if (this->isSplit)
	{
		this->cnt += 0.1;
		this->moveDeltaX += 0.1 * ((this->cnt - 8.0) * (this->cnt - 8.0));
	}
}

/* -------------------------------------------------------------
 描画処理
 ------------------------------------------------------------- */
void Scene23::draw()
{
	ofSetColor(0, 0, 0, 10);
	ofFill();
	ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	
	HumanDetector *detector = new HumanDetector(this->depthImg);
	vector<ofxCvBlob> blobs = detector->getHumanImage();
	
	if (blobs.size() > 0)
	{
		for (int i = 0; i < blobs.size(); i++)
		{
			ofxCvBlob blob = this->getRightBlob(blobs);
			
			if (!this->isSplit)
			{
				ofSetColor(255, 255, 255);
			}
			
			ofFill();
			if (this->isSplit)
			{
				ofSetColor(0, 255, 0);
			}
			ofBeginShape();
			for (int j = 0; j < blob.pts.size(); j++)
			{
				double x = blob.pts[j].x + this->moveDeltaX;
				double y = blob.pts[j].y;
				
				ofVertex(x, y);
			}
			ofEndShape();

			if (this->isSplit)
			{
				ofSetColor(255, 0, 255);
			}
			ofBeginShape();
			for (int k = 0; k < blob.pts.size(); k++)
			{
				double x = blob.pts[k].x - this->moveDeltaX;
				double y = blob.pts[k].y;
				
				ofVertex(x, y);
			}
			ofEndShape();
		}
	}
	
	SAFE_DELETE(detector);
}

void Scene23::split()
{
	if (this->isSplit)
	{
		this->moveDeltaX = 0.0;
		this->cnt = 0.0;
	}
	
	this->isSplit = !this->isSplit;
	
}

