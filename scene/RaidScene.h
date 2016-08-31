/*
FileName:	RaidScene.h
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/25 by PorcaM
*/

#ifndef __RAID_SCENE_H__
#define __RAID_SCENE_H__

#include "cocos2d.h"

class Raid : public cocos2d::Layer
{
public:
	/*
	Basic code of cocos2dx scene
	*/
	static cocos2d::Scene* createScene();
	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(Raid);

	/*
	Custom class functions
	Help for generating instances. 
	2016/08/24 by PorcaM
	*/
	void setBackground(cocos2d::Color4F);
	void getPlayer();
};

#endif // __RAID_SCENE_H__