#include "RangeNPC.h"

RangeNPC::RangeNPC(Tier _tier, int _index)
	:Character(_tier) {
	index = _index;
	int skillnum = 1;
	initSkillset(skillnum);
	return;
}
int RangeNPC::doAttack(Character *t) {
	mySkillSet[rand() % mySkillSet.size()]->activate(t, t[index]);
	return 0;
}

void RangeNPC::initSkillset(int _num) {
	vector<Skill *> entire;
	initRangeSkill(entire);
	for (int i = 0; i < _num; i++) {
		mySkillSet.push_back(entire[i]);
	}
	return;
}