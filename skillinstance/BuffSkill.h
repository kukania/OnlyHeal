#pragma once

#include "../parts/Skill.h"
#include "../Character.h"
#include <stdlib.h>

#define S_DAMAGE	0
#define	S_SPEED		1
#define S_ARMOR		2
#define	S_RGB_ALL	3
#define S_RGB_R		4
#define S_RGB_G		5
#define S_RGB_B		6

class BuffSkill : Skill {
private:
	float	value;
	int		stype;
public:
	BuffSkill();
	BuffSkill(SkillID, string, SkillID, time_ms, time_s, bool, float, int);
	virtual int activate(Character *t, Character c);
};