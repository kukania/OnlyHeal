/*
FileName: 	SkillFactory.h
Revision: 	2016/08/23 by PorcaM
*/

#pragma once
#include "..\parts\Skill.h"

class SkillFactory {
public:
	static Skill *getSkill(SkillType);
};