//
//  Scene8.hpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/18.
//

#ifndef Scene8_hpp
#define Scene8_hpp

#include <stdio.h>
#include "SceneBase.hpp"

class Scene8 : public SceneBase
{
public:
	Scene8(ofxKinect *kinect);
	virtual ~Scene8();
	
public:
	void update();
	void draw();
};

#endif /* Scene8_hpp */
