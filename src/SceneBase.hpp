//
//  SceneBase.hpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/18.
//

#ifndef SceneBase_hpp
#define SceneBase_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class SceneBase
{
public:
	SceneBase(ofxKinect *kinect);
	virtual ~SceneBase();

public:
	int sceneNum;					// シーン番号
	int near;						// 最小奥行き値（cm）
	int far;						// 最大奥行き値（cm）
	
private:
	void filteringDepthImage(int near, int far);			// 指定した範囲の奥行きデータだけ残す
	
protected:
	ofxKinect *kinect;
	ofxCvGrayscaleImage depthImg;
	
	ofxCvBlob getLeftBlob(vector<ofxCvBlob> blobs);			// 左端のBlobを返す
	ofxCvBlob getRightBlob(vector<ofxCvBlob> blobs);		// 右端のBlobを返す
	
	void ofSetHSVColor(int _h, int _s, int _v);
	void ofSetHSVColor(int _h, int _s, int _v, int _a);

public:
	virtual void update();
	virtual void draw();
};

#endif /* SceneBase_hpp */
