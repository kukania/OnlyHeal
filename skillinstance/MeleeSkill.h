#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"
#include <vector>

class MeleeSkill :public Skill {
private:
	float	factor;
public:
	// ID, name, parent, cooltime, time, multi, factor
	MeleeSkill(SkillID, string, SkillID, time_ms, time_s, bool, float);
	virtual int activate(Character *t, Character &c);
};

void initMeleeSkill(vector<Skill *> &);