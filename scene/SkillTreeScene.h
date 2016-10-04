/* ============================================================
FileName:	SkillTreeScene.h
Revision:	2016/09/11 by PorcaM
Modified: 	2016/09/22 by PorcaM

Interface for player skill controll. 
This class has ? components. All in SkillTreeLayer. 
	1. tabs
		Controll skilltree type. 
	2. SkillTreeFrame
		Draw skill buttons. 
	3. PlayerInfo
		Has information of player. 
		e.g. Point(skill point), skill set(equipment)
	4. SkillInfo
		Has information of skills. 
		Real instances from factory. 
============================================================ */

#ifndef __SKILLTREE_SCENE_H__
#define __SKILLTREE_SCENE_H__

#include "cocos2d.h"
#include "characters/Player.h"

class Character;

class SkillTreeScene : public cocos2d::Layer
{
public:
	/*
	Basic code of cocos2dx scene
	*/
	struct Data{
		Player *player;
	};
	static cocos2d::Scene* createScene(Data data);
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(SkillTreeScene);

	/*
	Custom class functions
	2016/09/11 by PorcaM
	*/
	void setBackground(cocos2d::Color4F);
	void set_data(Data data);
	void myInit();
 private:
	Data data_;
};

#endif // __SKILLTREE_SCENE_H__
