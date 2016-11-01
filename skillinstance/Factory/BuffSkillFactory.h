/* ============================================================
FileName: 	BuffSkillFactory.h
Revision:	2016/09/17 by PorcaM
Modified: 	2016/11/01 by PorcaM
============================================================ */

#pragma once

#include <string>

#include "cocos2d.h"
USING_NS_CC;

#include "parts/Skill.h"
#include "skillinstance/BuffSkill.h"
#include "skillinstance/Factory/SkillFactory.h"

class BuffSkillFactory :public SkillFactory{
public:
	void	initAllSkills();
	Skill*	createSkill();
	Skill*	createSkill(SkillID, string, time_ms, time_s, bool, float, MyRGB, StatType);
};
