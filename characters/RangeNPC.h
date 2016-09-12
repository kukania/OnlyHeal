/*
FileName:	RangeNPC.h
Modified:	2016/09/07 by PorcaM
*/

#pragma once

#include "Character.h"

class RangeNPC :public Character {
private:
public:
	RangeNPC(Tier);
	virtual void initSkillSet(int);
};