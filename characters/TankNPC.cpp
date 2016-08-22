#include "TankNPC.h"
#include "skillinstance\TankSkill.h"

TankNPC::TankNPC(Tier _tier, int _index)
	:Character(_tier) {
	index = _index;
	int skillnum = 3;
	initSkillset(skillnum);
	return;
}
int TankNPC::doAttack(Character *t) {
	mySkillSet[rand() % mySkillSet.size()]->activate(t, t[index]);
	return 0;
}

void TankNPC::initSkillset(int _num) {
	vector<Skill *> entire;
	TankSkill::initTankSkill(entire);
	for (int i = 0; i < _num; i++) {
		mySkillSet.push_back(entire[i]);
	}
	return;
}