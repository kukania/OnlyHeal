/*
FileName: 	SkillFactory.h
Revision: 	2016/08/23 by PorcaM
Modified:	2016/09/05 by PorcaM
*/

#pragma once
#include "..\parts\Skill.h"
#include "cocos2d.h"
USING_NS_CC;

class SkillFactory{
public:
	virtual Skill *createSkill(SkillType);
};

class HealSkillFactory : public SkillFactory {
public:
	virtual Skill *createSkill(SkillType);
};