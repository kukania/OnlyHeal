#pragma once

#include "../parts/Skill.h"
#include "../Character.h"
#include <stdlib.h>

class HealSkill :public Skill{
private:
	float	factor;
public:
	HealSkill();
	// ID, name, parent, cooltime, time, multi, factor
	HealSkill(SkillID, string, SkillID, time_ms, time_s, bool, float);
	virtual int activate(Character *t, Character &c);
};