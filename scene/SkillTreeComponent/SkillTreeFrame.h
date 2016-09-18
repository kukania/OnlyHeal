/*
FileName:	SkillTreeFrame.h
Revision:	2016/09/12 by PorcaM
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
	vector<SkillButton*> 	_sbv;
	SkillTree 				_st;
	SkillFactory* 			_pSf;
	ui::ScrollView* 		_scrollView;
	int 					_height;
	int 					_innerWidth;
public:
	SkillTreeFrame (ST_TYPE);
	~SkillTreeFrame ();
	void insertButton (Skill*, Vec2);
	void initScrollView ();
	ui::ScrollView* getScrollView ();
};