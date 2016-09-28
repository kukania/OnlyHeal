/* ============================================================
FileName:	SkillTreeFrame.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/27 by PorcaM

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

#include <vector>
#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "parts\Skill.h"
#include "scene\SkillTreeComponent\PlayerInfo.h"
#include "scene\SkillTreeComponent\SkillButton.h"
#include "scene\SkillTreeComponent\SkillInfo.h"
#include "skillinstance\Factory\SkillFactory.h"
#include "skilltree\SkillTree.h"

enum ST_TYPE{
	HealSkilltree, BuffSkilltree, DebuffSkilltree
};

class SkillTreeFrame {
 public:
	// renewal
	SkillTreeFrame();
	void InitWithType(Skill::Type type);
	void ClearContents();
	void InsertButton(Skill *skill);
	ui::ScrollView *get_scrollview();
	Skill::Type get_type();
	void set_type(Skill::Type type);
	PlayerInfo *get_player_info();
 private:
	// renewal
	void InitScrollView();
	void ClearScrollview();
	void ClearButtons();
	SkillFactory *get_factory();
	SkillTree *get_skilltree();
	Skill::Type 			type_;
	vector<SkillButton *> 	button_vec_;
	PlayerInfo 				player_info_;
	SkillInfo 				skill_info_;
	ui::ScrollView* 		scrollview_;
	int 					scrollview_height_;
	int 					scrollview_inner_width_;
};