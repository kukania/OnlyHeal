/*
FileName:	SkillFrame.h
Revision:	2016/08/30 by PorcaM
Modified:	2016/08/31 by PorcaM
*/


#pragma once
#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include "parts\Skill.h"
USING_NS_CC;

class SkillFrame : public CCNode {
private:
	Skill		*_skill;
	Label		*_label;
public:
	ui::Button	*_button;
	SkillFrame(Skill *);
	void initBG();
	void initLabel();
};