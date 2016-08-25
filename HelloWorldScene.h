#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
class HelloWorld : public cocos2d::Layer
{
public:
	DrawNode* backGround;
	cocos2d::Layer* characterGroup;
	DrawNode* statusHexa;
    static cocos2d::Scene* createScene();
	void makeBackGround();
	bool checkCharacterGroup(Point);
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	virtual bool onTouchBegan(Touch* touch, Event*);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
