#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

class MeleeSkill :public Skill {
private:
	float	_factor;
public:
	MeleeSkill();
	MeleeSkill(SkillID, string, time_ms, time_s, bool, float);
	virtual int activate(Character *t, Character &c);
	virtual int activate(Character *, Character &, int) {
		return 0;
	}
};