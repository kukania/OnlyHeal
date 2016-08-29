#include "RangeSkill.h"
#include "../myUtility.h"

RangeSkill::RangeSkill()
	:Skill(9999, "UNKOWN_RANGE", 0, 1, range_atk, false) {
	_factor = 1.0f;
}
RangeSkill::RangeSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor)
	:Skill(ID, name, cooltime, time, range_atk, multi) {
	_factor = factor;
}
int RangeSkill::activate(Character *t, Character &c) {
	int power = c.getStatus()->getDamage();
	int amount = DAMAGE_FOMULA(c, t[1]);
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		t[1].beAttacked(amount);
		c.getStatus()->addAgro(amount);
		_sleep(1000);
	}
	return 0;
}

void RangeSkill::initRangeSkill(vector<Skill *> &_ss) {
	Skill *ms[14];
	string  sPrefix[7] = { "기본", "숙련", "완숙", "전문", "기적", "전설", "신화" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		ms[i]		= new RangeSkill(100 + i, sPrefix[i] + "사격", fCoeffi[i], 1, false, fCoeffi[i]);
	}
	for (int i = 0; i < 7; i++) {
		ms[i + 7]	= new RangeSkill(107 + i, sPrefix[i] + "약포", fCoeffi[i], 15, false, fCoeffi[i] * 2);
	}
	for (int i = 0; i < 14; i++) {
		_ss.push_back(ms[i]);
	}
	return;
}