/*
FileName: 	BuffSkillFactory.h
Revision:	2016/09/17 by PorcaM
*/

#pragma once
#include "SkillFactory.h"
#include "skillinstance\BuffSkill.h"
#include "cocos2d.h"
USING_NS_CC;

class BuffSkillFactory :public SkillFactory{
public:
	void	initAllSkills();
	Skill*	createSkill();
	Skill*	createSkill (SkillID, string, time_ms, time_s, bool, float, MyRGB, StatType);
};