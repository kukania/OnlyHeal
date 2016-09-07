#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

class RangeSkill :public Skill {
private:
	float	_factor;
public:
	RangeSkill();
	RangeSkill(SkillID, string, time_ms, time_s, bool, float);
	virtual int activate(Character *, Character &);
	virtual int activate(Character *, Character &, int) {
		return 0;
	}
};