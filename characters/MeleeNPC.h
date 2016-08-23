#pragma once

#include "Character.h"

class MeleeNPC :public Character {
private:
	int		index;
	void	initSkillset(int);
public:
	MeleeNPC(Tier, int);
};