//
//  Scene15.hpp
//  Tsukuyomi
//
//  Created by Yusk1450 on 2018/01/22.
//

#ifndef Scene15_hpp
#define Scene15_hpp

#include <stdio.h>
#include "SceneBase.hpp"

class Scene15 : public SceneBase
{
public:
	Scene15(ofxKinect *kinect);
	virtual ~Scene15();
	
public:
	void update();
	void draw();
};

#endif /* Scene15_hpp */
