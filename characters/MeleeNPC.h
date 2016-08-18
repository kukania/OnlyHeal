#pragma once

#include "Character.h"
#include "skillinstance\MeleeSkill.h"

class MeleeNPC :public Character {
private:
	int		index;
	void	initSkillset(int);
public:
	MeleeNPC(Tier, int);
	int doAttack(Character *);
};