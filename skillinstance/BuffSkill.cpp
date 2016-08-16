#include "BuffSkill.h"

BuffSkill::BuffSkill() :Skill(999, "1234", 0, 0, 0, 0, false) {};
BuffSkill::BuffSkill(SkillID _ID, string _name, SkillID _parent,
	time_ms _cooltime, time_s _time, bool _multi, float _value, int _stype)
	:Skill(_ID, _name, _parent, _cooltime, _time, T_BUFF, _multi) {
	value = _value;
	stype = _stype;
}
int BuffSkill::activate(Character *t, Character c) {
	int power = c.getStatus()->getDamage();
	float factor = (power / 9999)*value;
	setCooldown();
	switch (stype) {
	case S_DAMAGE:
		if (isMulti()) {
			int amount[4];
			for (int i = 2; i < 6; i++) {
				amount[i - 2] = t[i].getStatus()->getDamage()*factor;
				t[i].getStatus()->addDamage(amount[i - 2]);
			}
			//_sleep(1000 * time);
			for (int i = 2; i < 6; i++) {
				t[i].getStatus()->addDamage(-amount[i - 2]);
			}
		}
		else {
			int amount = t[0].getStatus()->getDamage()*factor;
			t[0].getStatus()->addDamage(amount);
			//_sleep(1000 * time);
			t[0].getStatus()->addDamage(-amount);
		}
		break;
	case S_SPEED:
		int amount = 0;
		break;
	case S_ARMOR:
		if (isMulti()) {
			int amount[4];
			for (int i = 2; i < 6; i++) {
				amount[i - 2] = t[i].getStatus()->getDefence()*factor;
				t[i].getStatus()->addDefence(amount[i - 2]);
			}
			//_sleep
			for (int i = 2; i < 6; i++) {
				t[i].getStatus()->addDefence(-amount[i - 2]);
			}
		}
		else {
			int amount = t[0].getStatus()->getDefence()*factor;
			t[0].getStatus()->addDefence(amount);
			//sleep
			t[0].getStatus()->addDefence(-amount);
		}
	default:
		break;
	}
	return 0;
}