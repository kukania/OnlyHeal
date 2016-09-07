/*
FileName:	MeleeNPC.h
Modified:	2016/09/07 by PorcaM
*/

#pragma once

#include "Character.h"

class MeleeNPC :public Character {
private:
public:
	MeleeNPC(Tier);
	virtual void	initSkillSet(int);
};