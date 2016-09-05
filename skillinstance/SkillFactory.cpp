/*
FileName: 	SkillFactory.cpp
Revision: 	2016/08/23 by PorcaM
Modified:	2016/09/05 by PorcaM
*/

#include "SkillFactory.h"
#include "skillinstance\HealSkill.h"

Skill* SkillFactory::createSkill(SkillType type) {
	Skill* skill = NULL;
	return skill;
}

Skill* HealSkillFactory::createSkill(SkillType) {
	return new HealSkill();
}