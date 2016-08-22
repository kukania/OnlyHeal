#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"
#include <vector>

class MeleeSkill :public Skill {
private:
	float	factor;
public:
	// ID, name, parent, cooltime, time, multi, factor
	MeleeSkill(SkillID, string, time_ms, time_s, bool, float);
	virtual int activate(Character *t, Character &c);
	virtual int activate(Character *, Character &, int) {
		return 0;
	}
	static void initMeleeSkill(vector<Skill *> &);
};