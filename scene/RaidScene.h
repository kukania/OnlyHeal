/*
FileName:	RaidScene.h
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/25 by PorcaM
*/

#ifndef __RAID_SCENE_H__
#define __RAID_SCENE_H__
#include"characters\Character.h"
#include "cocos2d.h"
#include"ui/CocosGUI.h"
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
	//by kukania
};
#endif // __RAID_SCENE_H__
