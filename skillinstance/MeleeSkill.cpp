#include "MeleeSkill.h"
#include "myUtility.h"

MeleeSkill::MeleeSkill(SkillID _ID, string _name, 
	time_ms _cooltime, time_s _time, bool _multi, float _factor)
	:Skill(_ID, _name, _cooltime, _time, melee, _multi) {
	factor = _factor;
}
int MeleeSkill::activate(Character *t, Character &c) {
	int power = c.getStatus()->getDamage();
	MyRGB rgb1, rgb2;
	rgb1 = c.getStatus()->getMyRGBDamage();
	rgb2 = t[1].getStatus()->getMyRGBDefence();
	int amount = (1 + calcRGBFomula(rgb1, rgb2))*(c.getStatus()->getDamage() - t[1].getStatus()->getDefence() / 4);
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		t[1].beAttacked(amount / getTime());
		c.getStatus()->addAgro(amount / getTime());
		_sleep(1000);
	}
	return 0;
}

void MeleeSkill::initMeleeSkill(vector<Skill *> &_ss) {
	Skill *ms[14];
	string  sPrefix[7] = { "�⺻", "����", "�ϼ�", "����", "����", "����", "��ȭ" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		ms[i] = new MeleeSkill(100 + i, sPrefix[i] + "��Ÿ", fCoeffi[i], 1, false, fCoeffi[i]);
	}
	for (int i = 0; i < 7; i++) {
		ms[i+7] = new MeleeSkill(107 + i, sPrefix[i] + "����", fCoeffi[i], 30, false, fCoeffi[i]*2);
	}
	for (int i = 0; i < 14; i++) {
		_ss.push_back(ms[i]);
	}
	return;
}