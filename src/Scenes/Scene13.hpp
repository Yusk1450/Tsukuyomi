//
//  Scene13.hpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#ifndef Scene13_hpp
#define Scene13_hpp

#include <stdio.h>
#include "SceneBase.hpp"

class Scene13 : public SceneBase
{
public:
	Scene13(ofxKinect *kinect);
	virtual ~Scene13();
	
public:
	void update();
	void draw();
};

#endif /* Scene13_hpp */
