/*
FileName:	RaidScene.h
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/25 by PorcaM
*/

#ifndef __RAID_SCENE_H__
#define __RAID_SCENE_H__
<<<<<<< HEAD
#include "characters\Character.h"
#include "RaidComponent\UnitFrame.h"
#include "RaidComponent\BossFrame.h"
#include "RaidComponent\SkillFrame.h"
=======
#include"characters\Character.h"
#include "RaidComponent\BossFrame.h"
>>>>>>> 989a315e80dd1bb9ac4cc6abded779051bcb362b
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#define SKILLNUM 21
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
	cocos2d::ui::ScrollView *scv;
	Point skillBtnPosition[SKILLNUM];
	ui::Button *selectedBtn;
	static int selectedNum;
	BossFrame *bf;
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
	void doAttackChar0(float fd);
	void doAttackChar2(float fd);
	void doAttackChar3(float fd);
	void doAttackChar4(float fd);
	void doAttackChar5(float fd);
	//by kukania
};
#endif // __RAID_SCENE_H__
