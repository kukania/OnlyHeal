#include "HealSkill.h"

HealSkill::HealSkill()
	:Skill(9999, "UNKOWN_HEAL", 0, 1, heal, false){
	_factor = 1.0f;
}
HealSkill::HealSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor)
	:Skill(ID, name, cooltime, time, heal, multi) {
	_factor = factor;
}
int HealSkill::activate(Character **t, Character &c) {
	int power	= c.getStatus()->getDamage();
	int amount	= _factor * power / getTime();
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		if (isMulti()) {
			for (int i = 2; i < 6; i++) {
				if(!t[i]->checkDie())
					t[i]->getStatus()->addHP(amount);
			}
		}
		else {
			t[0]->getStatus()->addHP(amount);
		}
	}
	return 0;
}

int HealSkill::activate(Character **t, Character &c, int num) {
	int power = c.getStatus()->getDamage();
	int amount = _factor * power / getTime();
	if (t[num]->checkDie())
		return 0;
	else {
		setCooldown();
		t[num]->getStatus()->addHP(amount);
	}
	return 0;
}