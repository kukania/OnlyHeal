#include "HealSkill.h"

HealSkill::HealSkill() :Skill(999, "1234", 0, 0, 0, false) {};
HealSkill::HealSkill(SkillID _ID, string _name, 
	time_ms _cooltime, time_s _time, bool _multi, float _factor)
	:Skill(_ID, _name, _cooltime, _time, T_HEAL, _multi) {
	factor = _factor;
}
int HealSkill::activate(Character *t, Character &c) {
	int power = c.getStatus()->getDamage();
	int amount = factor * power / time;
	setCooldown();
	for (int i = 0; i < time; i++) {
		if (isMulti()) {
			for (int i = 2; i < 6; i++) {
				t[i].getStatus()->addHP(amount);
			}
		}
		else {
			t[0].getStatus()->addHP(amount);
		}
		//_sleep(1000);
	}
	return 0;
}

void HealSkill::initHealSkill(vector<Skill *> &_ss) {
	Skill *hs[22];
	string  sPrefix[7] = { "�⺻", "����", "�ϼ�", "����", "����", "����", "��ȭ" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		hs[i] = new HealSkill(i + 1, sPrefix[i] + "����", fCoeffi[i], false, fCoeffi[i], 1);
	}
	for (int i = 0; i < 7; i++) {
		hs[i + 7] = new HealSkill(i + 8, sPrefix[i] + "����",fCoeffi[i] * 2, true, fCoeffi[i], 1);
	}
	for (int i = 0; i < 7; i++) {
		hs[i + 14] = new HealSkill(i + 15, sPrefix[i] + "����", fCoeffi[i], false, fCoeffi[i] * 2, 10);
	}
	hs[21] = new HealSkill(22, "1234", 5, true, 3, 5);
}
int HealSkill::activate(Character *, Character &, int) {
	return 0;
}