#pragma once

#include "Character.h"
#include "skillinstance\TankSkill.h"

class TankNPC :public Character {
private:
	int		index;
	void	initSkillset(int);
public:
	TankNPC(Tier, int);
	int doAttack(Character *);
};