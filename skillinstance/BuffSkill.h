#pragma once

#include "../parts/Skill.h"
#include "../characters/Character.h"

#define S_DAMAGE	0
#define	S_SPEED		1
#define S_ARMOR		2
#define	S_MyRGB_DAM	3
#define S_MyRGB_DEF	4

class BuffSkill : public Skill {
private:
	float	value;	// max buff
	int		stype;
	MyRGB		rgb;
public:
	BuffSkill();
	BuffSkill(SkillID, string, time_ms, time_s, bool, float, MyRGB, int);
	virtual int activate(Character *t, Character &c);
	virtual int activate(Character *t, Character &c, int a);
};