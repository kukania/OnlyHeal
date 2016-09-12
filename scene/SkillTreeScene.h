/*
FileName:	SkillTreeScene.h
Revision:	2016/09/11 by PorcaM
*/

#ifndef __SKILLTREE_SCENE_H__
#define __SKILLTREE_SCENE_H__

#include "cocos2d.h"

class Character;

class SkillTreeScene : public cocos2d::Layer
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
	CREATE_FUNC(SkillTreeScene);

	/*
	Custom class functions
	2016/09/11 by PorcaM
	*/
	void setBackground(cocos2d::Color4F);
};

#endif // __SKILLTREE_SCENE_H__
