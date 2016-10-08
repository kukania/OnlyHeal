/* ==================================================
FileName:	SkillFrame.h
Revision:	2016/08/30 by PorcaM
Modified:	2016/10/08 by PorcaM
================================================== */


#pragma once

#include <string>

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "parts/Skill.h"
USING_NS_CC;

class SkillFrame : public CCNode {

 public:
	ui::Button	*_button;
	SkillFrame(string name);
	void initBG();
	void initLabel();
 private:
	//Skill		*_skill;
	Label		*_label;
	string		name_;
};