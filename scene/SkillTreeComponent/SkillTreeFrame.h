/*
FileName:	SkillTreeFrame.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/22 by PorcaM
*/

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "parts\Skill.h"
#include "skilltree\SkillTree.h"
#include "SkillButton.h"
#include "skillinstance/Factory/SkillFactory.h"
#include <vector>
USING_NS_CC;

enum ST_TYPE{
	HealSkilltree, BuffSkilltree, DebuffSkilltree
};

class SkillTreeFrame {
private:
	vector<SkillButton*> 	_buttons;
	SkillTree 				_skilltree;
	SkillFactory** 			_factories;
	ui::ScrollView* 		_scrollview;
	Label* 					_point;
	int 					_height;
	int 					_innerWidth;
	void insertButton (Skill*, SkillNode*, Vec2);
	void initScrollView ();
	void initPoint ();
	void clearScrollview ();
	void clearButtons ();
public:
	SkillTreeFrame (ST_TYPE);
	~SkillTreeFrame ();
	void initWithType (ST_TYPE);
	ui::ScrollView* getScrollView ();
};