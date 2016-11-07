/*
FileName: 	DebuffSkillFactory.h
Revision:	2016/09/17 by PorcaM
*/

#pragma once
#include "SkillFactory.h"
#include "skillinstance/Instance/BuffSkill.hpp"
#include "cocos2d.h"
USING_NS_CC;

class DebuffSkillFactory :public SkillFactory{
public:
	void	initAllSkills();
	Skill*	createSkill();
	Skill*	createSkill (SkillID, string, time_ms, time_s, bool, float, MyRGB, StatType);
};