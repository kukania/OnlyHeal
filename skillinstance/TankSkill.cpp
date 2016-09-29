#include "TankSkill.h"

TankSkill::TankSkill()
	:Skill(9999, "UNKOWN_TANK", 0, 1, tank, false) {
	_factor = 1.0f;
}
TankSkill::TankSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor)
	:Skill(ID, name, cooltime, time, tank, multi) {
	_factor = factor;
}
int TankSkill::activate(Character **t, Character &c) {
	int power = c.getStatus()->getDamage();
	int amount = power*_factor;
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		c.getStatus()->addAgro(amount);
		//_sleep(1000);
	}
	return 0;
}

void TankSkill::initTankSkill(vector<Skill *> &_ss) {
	Skill *ms[14];
	string  sPrefix[7] = { "기본", "숙련", "완숙", "전문", "기적", "전설", "신화" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		ms[i]		= new TankSkill(50 + i, sPrefix[i] + "도발", fCoeffi[i], 1, false, fCoeffi[i]);
	}
	for (int i = 0; i < 7; i++) {
		ms[i + 7]	= new TankSkill(57 + i, sPrefix[i] + "포효", fCoeffi[i], 10, true, fCoeffi[i] * 2);
	}
	for (int i = 0; i < 14; i++) {
		_ss.push_back(ms[i]);
	}
	return;
}