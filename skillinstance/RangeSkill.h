#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

class RangeSkill :public Skill {
private:
	float	factor;
public:
	RangeSkill(SkillID, string, SkillID, time_ms, time_s, bool, float);
	virtual int activate(Character *, Character &);
};

void initRangeSkill(vector<Skill *> &);