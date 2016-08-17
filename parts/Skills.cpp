#include "Skill.h"
#include "../Character.h"
#include <stdlib.h>

#define S_DAMAGE	0
#define	S_SPEED		1
#define S_ARMOR		2
#define	S_RGB		3

class HealSkill : Skill {
private:
	float   factor;                       // efficienty of skill
public:
	HealSkill() :Skill(999, "1234", 0, 0, 0, 0, false) {};
	HealSkill(SkillID _ID, string _name, SkillID _parent,
		time_ms _cooltime, time_s _time, bool _multi, float _factor)
		:Skill(_ID, _name, _parent, _cooltime, _time, T_HEAL, _multi) {
		factor = _factor;
	}
	virtual int activate(Character *t, Character c) {
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
			_sleep(1000);
		}
		return 0;
	}
};

class BuffSkill : Skill {
private:
	float	value;
	int		stype;
public:
	BuffSkill() :Skill(999, "1234", 0, 0, 0, 0, false) {};
	BuffSkill(SkillID _ID, string _name, SkillID _parent,
		time_ms _cooltime, time_s _time, bool _multi, float _value, int _stype)
		:Skill(_ID, _name, _parent, _cooltime, _time, T_BUFF, _multi) {
		value = _value;
		stype = _stype;
	}
	virtual int activate(Character *t, Character c) {
		int power = c.getStatus()->getDamage();
		float factor = (power / 9999)*value;
		setCooldown();
		switch (stype) {
		case S_DAMAGE:
			if (isMulti()) {
				int amount[4];
				for (int i = 2; i < 6; i++) {
					amount[i-2] = t[i].getStatus()->getDamage()*factor;
					t[i].getStatus()->addDamage(amount[i-2]);
				}
				//_sleep(1000 * time);
				for (int i = 2; i < 6; i++) {
					t[i].getStatus()->addDamage(-amount[i-2]);
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
					amount[i-2] = t[i].getStatus()->getDefence()*factor;
					t[i].getStatus()->addDefence(amount[i-2]);
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
};

void initSkills() {
	HealSkill hs[22];
	string  sPrefix[7] = { "기본", "숙련", "완숙", "전문", "기적", "전설", "신화" };
	float   fCoeffi[7] = { 1.0f, 1.2f, 1.5f, 2.0f, 3.0f, 5.0f, 10.0f };
	for (int i = 0; i < 7; i++) {
		hs[i] = HealSkill(i + 1, sPrefix[i] + "힐링", i, fCoeffi[i], false, fCoeffi[i], 1);
	}
	for (int i = 0; i < 7; i++) {
		hs[i + 7] = HealSkill(i + 8, sPrefix[i] + "광힐", i + 7, fCoeffi[i] * 2, true, fCoeffi[i], 1);
	}
	for (int i = 0; i < 7; i++) {
		hs[i + 14] = HealSkill(i + 15, sPrefix[i] + "힐샘", i + 14, fCoeffi[i], false, fCoeffi[i] * 2, 10);
	}
	hs[21] = HealSkill(22, "1234", 4, 5, true, 3, 5);
}