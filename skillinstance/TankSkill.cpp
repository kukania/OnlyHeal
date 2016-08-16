#include "TankSkill.h"

TankSkill::TankSkill(SkillID _ID, string _name, SkillID _parent,
	time_ms _cooltime, time_s _time, bool _multi, float _factor)
	:Skill(_ID, _name, _parent, _cooltime, _time, 3, _multi) {
	factor = _factor;
}
int TankSkill::activate(Character *t, Character &c) {
	int power = c.getStatus()->getDamage();
	int amount = power*factor;
	for (int i = 0; i < time; i++) {
		c.getStatus()->addAgro(amount);
		_sleep(1000);
	}
	return 0;
}

void initTankSkill() {
	Skill *ms[14];
	string  sPrefix[7] = { "기본", "숙련", "완숙", "전문", "기적", "전설", "신화" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		ms[i] = new TankSkill(50 + i, sPrefix[i] + "도발", 49 + i, fCoeffi[i], 1, false, fCoeffi[i]);
	}
	for (int i = 0; i < 7; i++) {
		ms[i + 7] = new TankSkill(57 + i, sPrefix[i] + "포효", 56 + i, fCoeffi[i], 10, false, fCoeffi[i] * 2);
	}
}