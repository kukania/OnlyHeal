#include "BuffSkill.hpp"

#define MEMBER_BEGIN	2
#define MEMBER_END		6

BuffSkill::BuffSkill() 
	:Skill(9999, "UNKNOW_BUFF", 0, 1, buff, false) {
};
BuffSkill::BuffSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float value, MyRGB rgb, StatType stype)
	:Skill(ID, name, cooltime, time, buff, _multi) {
	_value	= value;
	_stype	= stype;
	_rgb	= rgb;
}

int BuffSkill::activate(Character **t, Character &c) {
#define ADD_FIELD(field) getStatus()->add##field
	int power = c.getStatus()->getDamage();
	float factor = (power / 9999)*_value;
	setCooldown();
	switch (_stype) {
	case damage:
		if (isMulti()) {
			int amount[4];
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				amount[i - MEMBER_BEGIN] = t[i]->getStatus()->getDamage()*factor;
				t[i]->ADD_FIELD(Damage)(amount[i - MEMBER_BEGIN]);
			}
			//_sleep(1000 * time);
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->getStatus()->addDamage(-amount[i - MEMBER_BEGIN]);
			}
		}
		else {
			int amount = t[0]->getStatus()->getDamage()*factor;
			t[0]->getStatus()->addDamage(amount);
			//_sleep(1000 * time);
			t[0]->getStatus()->addDamage(-amount);
		}
		break;
	case speed:
		if (isMulti()) {
			float amount[4];
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				amount[i - MEMBER_BEGIN] = t[i]->getStatus()->getSpeed()*factor;
				t[i]->getStatus()->addSpeed(amount[i - MEMBER_BEGIN]);
			}
			//sleep
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->getStatus()->addSpeed(-amount[i - MEMBER_BEGIN]);
			}
		}
		else {
			float amount = t[0]->getStatus()->getSpeed()*factor;
			t[0]->getStatus()->addSpeed(amount);
			//sleep
			t[0]->getStatus()->addSpeed(-amount);
		}
		break;
	case armor:
		if (isMulti()) {
			int amount[4];
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				amount[i - MEMBER_BEGIN] = t[i]->getStatus()->getDefence()*factor;
				t[i]->getStatus()->addDefence(amount[i - MEMBER_BEGIN]);
			}
			//_sleep
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->getStatus()->addDefence(-amount[i - MEMBER_BEGIN]);
			}
		}
		else {
			int amount = t[0]->getStatus()->getDefence()*factor;
			t[0]->getStatus()->addDefence(amount);
			//sleep
			t[0]->getStatus()->addDefence(-amount);
		}
		break;
	case rgbDa:
		if (isMulti()) {
			MyRGB amount = _rgb*factor;
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->beBuffedDamage(amount);
			}
			//_sleep
			factor *= -1;
			amount = _rgb*factor;
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->beBuffedDamage(amount);
			}
		}
		else {
			MyRGB amount = _rgb*factor;
			t[0]->beBuffedDamage(amount);
			//sleep
			factor *= -1;
			amount = _rgb*factor;
			t[0]->beBuffedDamage(amount);
		}
		break;
	case rgbDe:
		if (isMulti()) {
			MyRGB amount = _rgb*factor;
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->beBuffedDefence(amount);
			}
			//_sleep
			factor *= -1;
			amount = _rgb*factor;
			for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {
				t[i]->beBuffedDefence(amount);
			}
		}
		else {
			MyRGB amount = _rgb*factor;
			t[0]->beBuffedDefence(amount);
			//sleep
			factor *= -1;
			amount = _rgb*factor;
			t[0]->beBuffedDefence(amount);
		}
		break;
	default:
		break;
	}
	return 0;
#undef ADD_FIELD
}

int BuffSkill::activate(Character **t, Character &c, int a) {
	/* macro define */
#define ADD_FIELD(field) getStatus()->add##field
#define GET_FIELD(field) getStatus()->get##field()
#define AFFECT_INT(field)\
	if(isMulti()){\
		for (int i = MEMBER_BEGIN; i < MEMBER_END; i++){\
			int amount = t[i]->GET_FIELD(field)*factor;\
			t[i]->ADD_FIELD(field)(amount);\
		}\
	}\
	else{\
		int amount = t[0]->GET_FIELD(field)*factor;\
		t[0]->ADD_FIELD(field)(amount);\
	}
#define AFFECT_RGB(field)\
	if (isMulti()) {\
		MyRGB amount = _rgb*factor;\
		for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) {\
			t[i]->beBuffed##field(amount);\
		}\
	}\
	else {\
		MyRGB amount = _rgb*factor;\
		t[0]->beBuffed##field(amount);\
	}

	/* real code */
	int power = c.getStatus()->getDamage();
	float factor = (power / 9999)*_value*a;
	setCooldown();
	switch (_stype) {
	case damage:
		AFFECT_INT(Damage)
		break;
	case speed:
		AFFECT_INT(Speed)
		break;
	case armor:
		AFFECT_INT(Defence)
		break;
	case rgbDa:
		AFFECT_RGB(Damage)
		break;
	case rgbDe:
		AFFECT_RGB(Defence)
		break;
	default:
		break;
	}
	return 0;
#undef AFFECT_RGB
#undef AFFECT_INT
#undef GET_FIELD
#undef ADD_FIELD
}

void initBuffSkill() {
	BuffSkill *bs[10];
	bs[0] = new BuffSkill(51, "goodbuff", 10 * SECOND, 30, false, 0.3f, MyRGB(0, 0, 0), damage);
}