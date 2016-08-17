#pragma once

#include "../parts/Skill.h"
#include "../Character.h"
#include <stdlib.h>

class TankSkill :public Skill {
private:
	float	factor;
public:
	TankSkill(SkillID, string, SkillID, time_ms, time_s, bool, float);
	virtual int activate(Character *, Character &);
};