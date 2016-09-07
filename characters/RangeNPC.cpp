/*
FileName:	RangeNPC.h
Modified:	2016/09/07 by PorcaM
*/

#include "RangeNPC.h"
#include "skillinstance\RangeSkill.h"
#include "skillinstance\Factory\RangeSkillFactory.h"
#include <cstdio>

RangeNPC::RangeNPC(Tier tier)
	:Character(tier) {
	int skillnum = (tier.getLevel() / 80) * 14;
	initSkillSet(skillnum);
}

void	RangeNPC::initSkillSet(int skillnum) {
	RangeSkillFactory rsf;
	Skill** list = rsf.getSkillsList(skillnum);
	for (int i = 0; i < skillnum; i++) {
		mySkillSet.push_back(list[i]);
	}
	return;
}