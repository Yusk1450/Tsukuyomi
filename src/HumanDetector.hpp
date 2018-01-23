//
//  HumanDetector.hpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/19.
//

#ifndef HumanDetector_hpp
#define HumanDetector_hpp

#include <stdio.h>
#include "ofxOpenCv.h"

class HumanDetector
{
public:
	HumanDetector(ofxCvGrayscaleImage &img);
	virtual ~HumanDetector();

private:
	ofxCvGrayscaleImage grayImg;
	
public:
	vector<ofxCvBlob> getHumanImage();		// 人間らしきBlob配列を返す
};

#endif /* HumanDetector_hpp */
