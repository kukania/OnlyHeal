/* ============================================================
FileName:	SkillButton.h
Revision:	2016/09/12 by PorcaM
Modified: 	2016/09/19 by PorcaM

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
#include "parts\Skill.h"
#include "skilltree\SkillTree.h"
USING_NS_CC;

class SkillButton : public CCNode{
private:
	ui::Button* 			_button;
	Label* 					_label;
	Skill* 					_skill;
	SkillNode* 				_node;
	SkillNode*		_prev;
	const static SkillTree* _tree;
public:
	SkillButton (Skill*, SkillNode*, SkillNode*);
	~SkillButton ();
	void initButton ();
	void initLabel ();
	void updateButton ();
};