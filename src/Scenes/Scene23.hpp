//
//  Scene23.hpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#ifndef Scene23_hpp
#define Scene23_hpp

#include <stdio.h>
#include "SceneBase.hpp"

class Scene23 : public SceneBase
{
public:
	Scene23(ofxKinect *kinect);
	virtual ~Scene23();
	
private:
	bool isSplit;
	double moveDeltaX;
	double cnt;
	
public:
	void update();
	void draw();
	
	void split();
};

#endif /* Scene23_hpp */
