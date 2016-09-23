/* ============================================================
FileName:	SkillTreeFrame.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/22 by PorcaM

This is a set of skillbuttons. 
Scrollable. 
Just viewer. 
This class update nothing. 
Draw net of skilltree. 

This class has ? componets. 
	1. SkillButtonFrame
		Draw scollview. 
		Has Skill buttons. 
		Show network about skilltree. 
		Has 3 instance with type(Heal, Buff, Debuff). 
	2. PlayerFrame
		2-1. Skillset
			Scrollable skill set interface. 
		2-2. Point
			Show player's skill point. 
============================================================ */

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