/*
FileName:	SkillButton.h
Revision:	2016/09/12 by PorcaM
*/

#pragma once

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "parts\Skill.h"
#include "skilltree\SkillTree.h"
USING_NS_CC;

class SkillButton : public CCNode{
private:
	ui::Button* 	_button;
	Label* 			_label;
	Skill* 			_skill;
public:
	SkillButton (Skill* skill);
	~SkillButton ();
	void initButton ();
	void initLabel ();
};