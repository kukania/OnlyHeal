#pragma once

#include "Character.h"

class TankNPC :public Character {
private:
	int		index;
	void	initSkillset(int);
public:
	TankNPC(Tier, int);
	int doAttack(Character *);
};