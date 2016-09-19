#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

class HealSkill :public Skill{
private:
	float	_factor;
public:
	HealSkill();
	HealSkill(SkillID, string, time_ms, time_s, bool, float);
	virtual int activate(Character **t, Character &c);
	virtual int activate(Character **, Character &, int);
};