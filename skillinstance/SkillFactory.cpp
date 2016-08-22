/*
FileName: 	SkillFactory.cpp
Revision: 	2016/08/23 by PorcaM
*/

#include "SkillFactory.h"
#include "skillinstance\HealSkill.h"

Skill *SkillFactory::getSkill(SkillType type) {
	Skill *retVal = NULL;
	switch (type) {
	case heal:
		retVal = new HealSkill();
		break;
	case buff:
		break;
	case debuff:
		break;
	case tank:
		break;
	case melee:
		break;
	case range:
		break;
	case unknown:
		break;
	default:
		break;
	}
	return retVal;
}