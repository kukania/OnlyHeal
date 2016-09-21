/*
FileName:	MeleeNPC.cpp
Modified:	2016/09/07 by PorcaM
*/

#include "MeleeNPC.h"
#include "skillinstance\MeleeSkill.h"
#include "skillinstance\Factory\MeleeSkillFactory.h"
#include <cstdio>

MeleeNPC::MeleeNPC(Tier tier)
	:Character(tier) {
	int skillnum = (tier.getLevel()*14 / 80);
	initSkillSet(skillnum);
}

void	MeleeNPC::initSkillSet(int skillnum) {
	MeleeSkillFactory msf;
	msf.initAllSkills();
	Skill** list = msf.getSkillsList(skillnum);
	for (int i = 0; i < skillnum; i++) {
		mySkillSet.push_back(list[i]);
	}
	return;
}