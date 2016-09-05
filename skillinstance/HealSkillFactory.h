/*
FileName: 	HealSkillFactory.h
Revision:	2016/09/05 by PorcaM
*/

#pragma once
#include "..\parts\Skill.h"
#include "cocos2d.h"
#include <vector>
USING_NS_CC;

class HealSkillFactory {
private:
	vector<Skill*> Akashic;
public:
	HealSkillFactory();
	void	initAllSkills();
	Skill*	createSkill();
	Skill*	createSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor);
	Skill*	getSkill(int);
	Skill** getSkillsList(int);
};