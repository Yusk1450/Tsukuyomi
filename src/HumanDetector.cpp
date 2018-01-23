//
//  HumanDetector.cpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/19.
//

#include "HumanDetector.hpp"

HumanDetector::HumanDetector(ofxCvGrayscaleImage &img)
{
	this->grayImg = img;
}

HumanDetector::~HumanDetector()
{
}

vector<ofxCvBlob> HumanDetector::getHumanImage()
{
	vector<ofxCvBlob> blobs;
	ofxCvContourFinder contourFinder;

	contourFinder.findContours(this->grayImg,
							   0, this->grayImg.getWidth() * this->grayImg.getHeight(), 10, true, true);
	
	if (contourFinder.blobs.size() > 0)
	{
		for (int i = 0; i < contourFinder.blobs.size(); i++)
		{
			ofxCvBlob blob = contourFinder.blobs[i];
			bool isHuman = false;
			
			// サイズが小さいBlobを弾く
			if (blob.boundingRect.width <= 50 || blob.boundingRect.height <= 50)
			{
				continue;
			}
			
			for (int j = 0; j < blob.pts.size(); j++)
			{
				if (blob.pts[j].y < ofGetWindowHeight()/2)
				{
					isHuman = true;
				}
			}
			
			if (isHuman)
			{
				blobs.push_back(blob);
			}
		}
	}
	
	return blobs;
}

