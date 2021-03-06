/*
FileName:	RaidScene.h
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/25 by PorcaM
*/

#ifndef __RAID_SCENE_H__
#define __RAID_SCENE_H__
#include "characters\Character.h"
#include "RaidComponent\BossFrame.h"
#include "scene/RaidComponent/unitFrame.h"
#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include<vector>
#include<list>
USING_NS_CC;
#define SKILLNUM 21
struct SkillInfo {
	Character *cl;
	int skillNum;
};
class Raid : public cocos2d::Layer
{
public:
	/*
	Basic code of cocos2dx scene
	*/
	static cocos2d::Scene* createScene();
	static cocos2d::Scene* createScene(Character **);
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Raid);
	
	
	/*************variable*******/
	Character **cl;
	UnitFrame *uf[4];
	cocos2d::ui::ScrollView *scv;
	std::vector<Point> skillBtnPosition;
	ui::Button *selectedBtn;
	static int selectedNum;
	BossFrame *bf;
	std::list<SkillInfo>skillStorage;
	int playerSkillTarget;
	/****************************/
	/*
	Custom class functions
	Help for generating instances. 
	2016/08/24 by PorcaM
	*/
	void setBackground(cocos2d::Color4F);
	void getPlayer();
	void initUnitGrid();
	void initBossFrame(Character *);
	void initSkillGrid();

	/*******************/
	void makeUnitFrame();
	void makeSkillScrollView();
	virtual bool onTouchBegan(Touch* touch, Event*);
	virtual void onTouchMoved(Touch *touch, Event*);
	virtual void onTouchEnded(Touch *touch, Event*);

	/**schedule**/
	void moveBossFrame(float fd);
	void playingFunc(float fd);
	void skillCoolDown(float fd);
	void frameUpdate(float fd);
	void checkGameOver(float fd);
	~Raid() {
		CCLOG("destructor!");
		this->autorelease();
	}
	//by kukania
};
#endif // __RAID_SCENE_H__
