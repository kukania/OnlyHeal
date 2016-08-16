#pragma once

#include "../parts/Skill.h"
#include "../Character.h"
#include <stdlib.h>

class MeleeSkill :public Skill {
private:
	float	factor;
public:
	// ID, name, parent, cooltime, time, multi, factor
	MeleeSkill(SkillID, string, SkillID, time_ms, time_s, bool, float);
	virtual int activate(Character *t, Character c);
};