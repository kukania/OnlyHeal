/* ============================================================
FileName:	SkillButton.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/28 by PorcaM

SkillButton is in SkillTreeFrame. 
This is a instance of that. 
Instance means individual skill. 
Functions
	1. Show information to user
		Information about skill
		e.g. skill usability, Learning net, 
	2. Update Skilltree
		Learn skill. 
	3. Update SkillSet
		Equipment skill. 
============================================================ */

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
USING_NS_CC;
#include "parts\Skill.h"
#include "skilltree\SkillTree.h"

class SkillButton : public CCNode{
 public:
	SkillButton (Skill *skill, SkillNode *node, SkillNode *prev);
	~SkillButton ();
	auto get_label();
	void set_label();
	auto get_button();
	void set_button();
	auto get_skill();
	void set_skill();
	auto get_node();
	void set_node();
	auto get_prev();
	void set_prev();

	// void initLabel ();
	// void updateButton ();
	// void initButton ();
 private:
 	void InitLabel();
 	void InitButton();
 	Label *label_;
 	ui::Button *button_;
	Skill *skill_;
	SkillNode *node_, *prev_;

	// ui::Button* 			_button;
	// Label* 					_label;
	// Skill* 					_skill;
	// SkillNode* 				_node;
	// SkillNode*		_prev;
	const static SkillTree* _tree;
};