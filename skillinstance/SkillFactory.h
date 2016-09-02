/*
FileName: 	SkillFactory.h
Revision: 	2016/08/23 by PorcaM
*/

#pragma once
#include "..\parts\Skill.h"
#include "cocos2d.h"
USING_NS_CC;

class SkillFactory{
public:
	static Skill *getSkill(SkillType);
};