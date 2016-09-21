/*
FileName:	TankNPC.cpp
Modified:	2016/09/07 by PorcaM
*/

#include "TankNPC.h"
#include "skillinstance\TankSkill.h"
#include "skillinstance\Factory\TankSkillFactory.h"
#include <cstdio>

TankNPC::TankNPC(Tier tier)
	:Character(tier) {
	int skillnum = (tier.getLevel()*14 / 80);
	initSkillSet(skillnum);
}

void	TankNPC::initSkillSet(int skillnum) {
	TankSkillFactory tsf;
	Skill** list = tsf.getSkillsList(skillnum);
	for (int i = 0; i < skillnum; i++) {
		mySkillSet.push_back(list[i]);
	}
	return;
}