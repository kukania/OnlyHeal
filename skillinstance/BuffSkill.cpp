#include "BuffSkill.h"

#define MEMBER_BEGIN	2
#define MEMBER_END		6

BuffSkill::BuffSkill() :Skill(999, "1234", 0, 0, 0, 0, false) {};
BuffSkill::BuffSkill(SkillID _ID, string _name, SkillID _parent,
	time_ms _cooltime, time_s _time, bool _multi, float _value, RGB _rgb, int _stype)
	:Skill(_ID, _name, _parent, _cooltime, _time, T_BUFF, _multi) {
	value	= _value;
	stype	= _stype;
	rgb		= _rgb;
}

int BuffSkill::activate(Character *t, Character c) {
	int power = c.getStatus()->getDamage();
	float factor = (power / 9999)*value;
	setCooldown();
	switch (stype) {
	case S_DAMAGE:
		if (isMulti()) {
			int amount[4];
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				amount[i - MEMBER_BEGIN] = t[i].getStatus()->getDamage()*factor;
				t[i].getStatus()->addDamage(amount[i - MEMBER_BEGIN]);
			}
			//_sleep(1000 * time);
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].getStatus()->addDamage(-amount[i - MEMBER_BEGIN]);
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
		if (isMulti()) {
			float amount[4];
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				amount[i - MEMBER_BEGIN] = t[i].getStatus()->getSpeed()*factor;
				t[i].getStatus()->addSpeed(amount[i - MEMBER_BEGIN]);
			}
			//sleep
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].getStatus()->addSpeed(-amount[i - MEMBER_BEGIN]);
			}
		}
		else {
			float amount = t[0].getStatus()->getSpeed()*factor;
			t[0].getStatus()->addSpeed(amount);
			//sleep
			t[0].getStatus()->addSpeed(-amount);
		}
		break;
	case S_ARMOR:
		if (isMulti()) {
			int amount[4];
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				amount[i - MEMBER_BEGIN] = t[i].getStatus()->getDefence()*factor;
				t[i].getStatus()->addDefence(amount[i - MEMBER_BEGIN]);
			}
			//_sleep
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].getStatus()->addDefence(-amount[i - MEMBER_BEGIN]);
			}
		}
		else {
			int amount = t[0].getStatus()->getDefence()*factor;
			t[0].getStatus()->addDefence(amount);
			//sleep
			t[0].getStatus()->addDefence(-amount);
		}
		break;
	case S_RGB_DAM:
		if (isMulti()) {
			RGB amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].beBuffedDamage(amount);
			}
			//_sleep
			factor *= -1;
			amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].beBuffedDamage(amount);
			}
		}
		else {
			RGB amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			t[0].beBuffedDamage(amount);
			//sleep
			factor *= -1;
			amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			t[0].beBuffedDamage(amount);
		}
		break;
	case S_RGB_DEF:
		if (isMulti()) {
			RGB amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].beBuffedDefence(amount);
			}
			//_sleep
			factor *= -1;
			amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i].beBuffedDefence(amount);
			}
		}
		else {
			RGB amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			t[0].beBuffedDefence(amount);
			//sleep
			factor *= -1;
			amount = RGB(rgb.getR*factor, rgb.getG*factor, rgb.getB*factor);
			t[0].beBuffedDefence(amount);
		}
		break;
	default:
		break;
	}
	return 0;
}

void initBuffSkill() {
	BuffSkill *bs[10];
	bs[0] = new BuffSkill(51, "goodbuff", 0, 10 * SECOND, 30, false, 0.3f, RGB(0, 0, 0), S_DAMAGE);
}