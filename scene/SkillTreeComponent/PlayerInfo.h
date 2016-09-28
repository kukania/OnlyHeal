/* ============================================================
FileName: 	PlayerInfo.h
Revision: 	2016/09/22 by PorcaM
Modified: 	2016/09/28 by PorcaM

This class has player's information used in skilltree. 
	1. Point
		This is cost for learning skill. 
		Updated when learn skill. (MUST BE UPDATED)
	2. SkillSet
		This is skills that used in RAID. 
		Updated when user want to. 
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "parts\Skill.h"  /* Perhaps this Lib is not essential. */
#include "scene\SkillTreeComponent\SkillButton.h"

class PlayerInfo{
 public:
	const int max_skill_num = 10;
	typedef int Point;
	typedef vector<SkillButton *> SkillVec;
	PlayerInfo();
	~PlayerInfo();
	int get_skill_num();
	void set_skill_num(int skill_num);
	Point get_point();
	void set_point(Point point);
	SkillVec get_slot();
	ui::ScrollView *get_scrollview();
 private:
 	void InitScrollview();
 	void InitLabelPoint();
 	int skill_num_;
	Point point_;
	SkillVec slot_;
	ui::ScrollView *scrollview_;
	Label *label_point_;
};