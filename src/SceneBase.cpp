//
//  SceneBase.cpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/18.
//

#include "SceneBase.hpp"

bool operator<(const ofxCvBlob& left, const ofxCvBlob& right)
{
	return left.centroid.x < right.centroid.x;
}

/* -------------------------------------------------------------
 コンストラクタ
 ------------------------------------------------------------- */
SceneBase::SceneBase(ofxKinect *kinect)
{
	this->sceneNum = -1;
	this->near = 1000;
	this->far = 3500;
	
	this->kinect = kinect;
}

/* -------------------------------------------------------------
 デストラクタ
 ------------------------------------------------------------- */
SceneBase::~SceneBase()
{
}

/* -------------------------------------------------------------
 更新処理
 ------------------------------------------------------------- */
void SceneBase::update()
{
	this->depthImg.clear();
	this->depthImg.allocate(this->kinect->getWidth(), this->kinect->getHeight());

	this->filteringDepthImage(this->near, this->far);
	this->depthImg.blur(5);
}

/* -------------------------------------------------------------
 描画処理
 ------------------------------------------------------------- */
void SceneBase::draw()
{
}

/* -------------------------------------------------------------
 指定した範囲の奥行きデータだけ残す
 ------------------------------------------------------------- */
void SceneBase::filteringDepthImage(int near, int far)
{
	unsigned char *pixels = this->depthImg.getPixels();
	
	for (int y = 0; y < this->kinect->getHeight(); y++)
	{
		for (int x = 0; x < this->kinect->getWidth(); x++)
		{
			int idx = this->kinect->getWidth() * y + x;
			int dis = this->kinect->getDistanceAt(x, y);
			
			if (dis > this->near && dis < this->far)
			{
				pixels[idx] = 255;
			}
			else
			{
				pixels[idx] = 0;
			}
		}
	}
}

/* -------------------------------------------------------------
 左端のBlobを返す
 ------------------------------------------------------------- */
ofxCvBlob SceneBase::getLeftBlob(vector<ofxCvBlob> blobs)
{
	if (blobs.size() <= 1)
	{
		return blobs[0];
	}
	
	sort(blobs.begin(), blobs.end());
	return blobs[0];
}

/* -------------------------------------------------------------
 右端のBlobを返す
 ------------------------------------------------------------- */
ofxCvBlob SceneBase::getRightBlob(vector<ofxCvBlob> blobs)
{
	if (blobs.size() <= 1)
	{
		return blobs[0];
	}
	
	sort(blobs.begin(), blobs.end());
	return blobs[blobs.size()-1];
}

void SceneBase::ofSetHSVColor(int _h, int _s, int _v, int _a){
	
	float s = (float)_s/100, v = (float)_v/100;
	if (s==0) {
		ofSetColor(255*v, 255*v, 255*v);
		return;
	}
	float r,g,b;
	int hi = (int)(floor((double)_h/60))%6;
	float f = (float)_h/60-(float)hi;
	float p = v*(1-s);
	float q = v*(1-f*s);
	float t = v*(1-(1-f)*s);
	switch (hi) {
		case 0:
			r=v;
			g=t;
			b=p;
			break;
		case 1:
			r=q;
			g=v;
			b=p;
			break;
		case 2:
			r=p;
			g=v;
			b=t;
			break;
		case 3:
			r=p;
			g=q;
			b=v;
			break;
		case 4:
			r=t;
			g=p;
			b=v;
			break;
		case 5:
			r=v;
			g=p;
			b=q;
			break;
		default:
			break;
	}
	ofSetColor(255*r, 255*g, 255*b, _a);
}

void SceneBase::ofSetHSVColor(int _h, int _s, int _v){
	ofSetHSVColor(_h, _s, _v, 255);
}

