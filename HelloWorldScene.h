#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include<vector>
USING_NS_CC;

#define MENUBTN 4
class HelloWorld : public cocos2d::Layer
{
public:
	std::vector<Vec2>positionArr;
	ui::ScrollView* scrollView;
	DrawNode* backGround;
	cocos2d::Layer* characterGroup;
	DrawNode* statusHexa;
	bool menuBtnTouched;
    static cocos2d::Scene* createScene();
	void makeBackGround();
	bool checkCharacterGroup(Point);
	
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	virtual bool onTouchBegan(Touch* touch, Event*);
	virtual void onTouchMoved(Touch *touch, Event*);
	virtual void onTouchEnded(Touch *touch, Event*);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
