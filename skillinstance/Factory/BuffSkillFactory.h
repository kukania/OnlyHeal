/*
FileName: 	BuffSkillFactory.h
Revision:	2016/09/17 by PorcaM
*/

#pragma once
#include "SkillFactory.h"
#include "parts\Skill.h"
#include "cocos2d.h"
USING_NS_CC;

class BuffSkillFactory :public SkillFactory{
public:
	void	initAllSkills();
	Skill*	createSkill();
	Skill*	createSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor);
};