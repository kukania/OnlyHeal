/*
FileName: 	BuffSkillFactory.cpp
Revision:	2016/09/17 by PorcaM
*/

#include "BuffSkillFactory.h"
#include "skillinstance/Instance/BuffSkill.hpp"
#include <string>

Skill*	BuffSkillFactory::createSkill() {
	Skill* skill = new BuffSkill();
	return skill;
}

Skill*	BuffSkillFactory::createSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float value, MyRGB rgb, StatType stype) {
	Skill* skill = new BuffSkill(ID, name, cooltime, time, multi, value, rgb, stype);
	return skill;
}

void	BuffSkillFactory::initAllSkills() {
	clearFactory ();
	return;
}