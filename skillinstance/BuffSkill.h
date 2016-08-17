#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

#define S_DAMAGE	0
#define	S_SPEED		1
#define S_ARMOR		2
#define	S_RGB_DAM	3
#define S_RGB_DEF	4

class BuffSkill : public Skill {
private:
	float	value;	// max buff
	int		stype;
	RGB		rgb;
public:
	BuffSkill();
	BuffSkill(SkillID, string, SkillID, time_ms, time_s, bool, float, RGB, int);
	virtual int activate(Character *t, Character &c);
};