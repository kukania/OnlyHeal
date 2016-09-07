/*
FileName:	TankNPC.h
Modified:	2016/09/07 by PorcaM
*/

#pragma once

#include "Character.h"

class TankNPC :public Character {
private:
public:
	TankNPC(Tier);
	virtual void	initSkillSet(int);
};