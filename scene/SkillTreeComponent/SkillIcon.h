/* ============================================================
FileName: 	SkillIcon.h
Revision: 	2016/10/02 by PorcaM
Modified: 	2016/10/02 by PorcaM
============================================================ */

#pragma once

#include <vector>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#include "parts/Skill.h"

class SkillIcon : public CCNode{
 public:
 	SkillIcon(Skill *skill);
 	~SkillIcon();
 	auto get_skill();
 	void set_skill(Skill *skill);
 	auto get_button();
 private:
 	void InitLabel();
	void InitButton();
 	Skill *skill_;  // for inforamtion about this skill
 	Label *label_;
 	ui::Button *button_;
};