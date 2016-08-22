#include "HealSkill.h"

HealSkill::HealSkill()
	:Skill(9999, "UNKOWN_HEAL", 0, 1, heal, false){
	_factor = 1.0f;
}
HealSkill::HealSkill(SkillID ID, string name, time_ms cooltime, 
	time_s time, bool multi, float factor)
	:Skill(ID, name, cooltime, time, heal, multi) {
	_factor = factor;
}
int HealSkill::activate(Character *t, Character &c) {
	int power	= c.getStatus()->getDamage();
	int amount	= _factor * power / getTime();
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		if (isMulti()) {
			for (int i = 2; i < 6; i++) {
				t[i].getStatus()->addHP(amount);
			}
		}
		else {
			t[0].getStatus()->addHP(amount);
		}
	}
	return 0;
}

void HealSkill::initHealSkill(vector<Skill *> &_ss) {
	Skill *hs[22];
	string  sPrefix[7] = { "±âº»", "¼÷·Ã", "¿Ï¼÷", "Àü¹®", "±âÀû", "Àü¼³", "½ÅÈ­" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		hs[i] = new HealSkill(i + 1, sPrefix[i] + "Èú¸µ", fCoeffi[i], false, fCoeffi[i], 1);
	}
	for (int i = 0; i < 7; i++) {
		hs[i + 7] = new HealSkill(i + 8, sPrefix[i] + "±¤Èú",fCoeffi[i] * 2, true, fCoeffi[i], 1);
	}
	for (int i = 0; i < 7; i++) {
		hs[i + 14] = new HealSkill(i + 15, sPrefix[i] + "Èú»ù", fCoeffi[i], false, fCoeffi[i] * 2, 10);
	}
	hs[21] = new HealSkill(22, "1234", 5, true, 3, 5);
	for (int i = 0; i < 22; i++) {
		_ss.push_back(hs[i]);
	}
}
int HealSkill::activate(Character *, Character &, int) {
	return 0;
}