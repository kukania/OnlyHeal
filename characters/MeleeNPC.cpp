#include "MeleeNPC.h"
#include "skillinstance\MeleeSkill.h"

MeleeNPC::MeleeNPC(Tier _tier, int _index)
	:Character(_tier) {
	index = _index;
	int skillnum = 3;
	initSkillset(skillnum);
	return;
}

void MeleeNPC::initSkillset(int _num) {
	vector<Skill *> entire;
	MeleeSkill::initMeleeSkill(entire);
	for (int i = 0; i < _num; i++) {
		mySkillSet.push_back(entire[i]);
	}
	return;
}