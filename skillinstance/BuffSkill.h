#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

enum StatType {
	damage, speed, armor, rgbDa, rgbDe
};

class BuffSkill : public Skill {
private:
	float		_value;
	StatType	_stype;
	MyRGB		_rgb;
public:
	BuffSkill();
	BuffSkill(SkillID, string, time_ms, time_s, bool, float, MyRGB, StatType);
	virtual int activate(Character *t, Character &c);
	virtual int activate(Character *t, Character &c, int a);
};