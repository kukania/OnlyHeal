#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include "scene/HelloWorldComponent/statusHexa.h"
#include "scene/HelloWorldComponent/ConsumableLayer.h"
#include "characters/Player.h"
#include "FileOperation.h"
#include<vector>

USING_NS_CC;

enum positionName{
	CHA,RAC,TER,SCROLLVIEW, MENUBTN
};
class HelloWorld : public cocos2d::Layer
{
public:
	FileOperation FM;//for wirte,read file
	Player *p;
	int touchNum;
	std::vector<Vec2>positionArr;
	ui::ScrollView* scrollView;
	DrawNode* backGround;
	cocos2d::Layer* characterGroup;
	DrawNode* statusHexa;
	DrawNode* playerStatusHexa;
	StatusHexa statusHexaContent;
	Label *showPlayerStatus[4]; //damage,defence,MaxHP,Tier
	ConsumableLayer *consumableLayer;

	bool menuBtnTouched;
	bool scrollViewShow;//flag for touch event
	short scrollViewType;

	static cocos2d::Scene* createScene();
	void makeBackGround();
	bool checkCharacterGroup(Point);
	void drawPlayerStatusHexa();
	void scrollViewSetting(int);
    
	//update
	void updateConsumableInventory(float fd);
    
	//debug
	void makePlayerWithItem();
	void makePlayerConsumable();
	void fileWriteTest();
	void fileReadTest();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	virtual bool onTouchBegan(Touch* touch, Event*);
	virtual void onTouchMoved(Touch *touch, Event*);
	virtual void onTouchEnded(Touch *touch, Event*);

    // implement the "static create()" method manually
	virtual bool init();
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
