/* ============================================================
FileName:	SkillTreeScene.h
Revision:	2016/09/11 by PorcaM
Modified: 	2016/10/09 by PorcaM
============================================================ */

#ifndef __SKILLTREE_SCENE_H__
#define __SKILLTREE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
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


	void OHInit();
 private:
	void InitLayer();
	void InitOuterFrame();
	void set_backgorund(cocos2d::Color4F);
	void set_data(Data data);
	Data data_;
	cocos2d::Size visible_size_;
	cocos2d::Layer *skilltree_layer_;
	cocos2d::ui::Button *close_btn_;
};

#endif // __SKILLTREE_SCENE_H__
