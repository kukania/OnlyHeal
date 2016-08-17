#include "RangeSkill.h"

float calcRGB(RGB rgb1, RGB rgb2) {
	int a = rgb1.getR() - rgb2.getR();
	if (a < 0) a = 0;
	int b = rgb1.getG() - rgb2.getG();
	if (b < 0) b = 0;
	int c = rgb1.getB() - rgb2.getB();
	if (c < 0) c = 0;
	return (a + b + c) / (3 * 255);
}

RangeSkill::RangeSkill(SkillID _ID, string _name, SkillID _parent,
	time_ms _cooltime, time_s _time, bool _multi, float _factor)
	:Skill(_ID, _name, _parent, _cooltime, _time, T_RANGE, _multi) {
	factor = _factor;
}
int RangeSkill::activate(Character *t, Character &c) {
	int power = c.getStatus()->getDamage();
	RGB rgb1, rgb2;
	rgb1 = c.getStatus()->getRGBDamage();
	rgb2 = t[1].getStatus()->getRGBDefence();
	int amount = (1 + calcRGB(rgb1, rgb2))*(c.getStatus()->getDamage() - t[1].getStatus()->getDefence() / 4);
	setCooldown();
	for (int i = 0; i < time; i++) {
		t[1].beAttacked(amount / time);
		c.getStatus()->addAgro(amount / time);
		_sleep(1000);
	}
	return 0;
}

void initRangeSkill() {
	Skill *ms[14];
	string  sPrefix[7] = { "기본", "숙련", "완숙", "전문", "기적", "전설", "신화" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		ms[i] = new RangeSkill(100 + i, sPrefix[i] + "사격", 99 + i, fCoeffi[i], 1, false, fCoeffi[i]);
	}
	for (int i = 0; i < 7; i++) {
		ms[i + 7] = new RangeSkill(107 + i, sPrefix[i] + "약포", 106 + i, fCoeffi[i], 15, false, fCoeffi[i] * 2);
	}
}