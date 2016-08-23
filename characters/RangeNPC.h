#pragma once

#include "Character.h"

class RangeNPC :public Character {
private:
	int		index;
	void	initSkillset(int);
public:
	RangeNPC(Tier, int);
	int doAttack(Character *);
};