#include "BuffSkill.hpp"

#define MEMBER_BEGIN    2
#define MEMBER_END      6

BuffSkill::BuffSkill()
	:Skill(9999, "UNKNOW_BUFF", 0, 1, buff, false) {};
BuffSkill::BuffSkill(SkillID  ID,
					 string	  name,
					 time_ms  cooltime,
					 time_s	  time,
					 bool	  multi,
					 float	  value,
					 MyRGB	  rgb,
					 StatType stype)
	:Skill(ID, name, cooltime, time, buff, _multi) {
	_value = value;
	_stype = stype;
	_rgb   = rgb;
}

int BuffSkill::activate(Character **t, Character& c) {
	return 0;
}

int BuffSkill::activate(Character **t, Character& c, int a) {
	/* macro define */
#define ADD_FIELD(field) getStatus()->add ## field
#define GET_FIELD(field) getStatus()->get ## field()
#define AFFECT_INT(field)								  \
	if (isMulti()) {									  \
		for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) { \
			int amount = t[i]->GET_FIELD(field) * factor; \
			t[i]->ADD_FIELD(field)(amount);				  \
		}												  \
	}													  \
	else {												  \
		int amount = t[0]->GET_FIELD(field) * factor;	  \
		t[0]->ADD_FIELD(field)(amount);					  \
	}
#define AFFECT_RGB(field)								  \
	if (isMulti()) {									  \
		MyRGB amount = _rgb * factor;					  \
		for (int i = MEMBER_BEGIN; i < MEMBER_END; i++) { \
			t[i]->beBuffed ## field(amount);			  \
		}												  \
	}													  \
	else {												  \
		MyRGB amount = _rgb * factor;					  \
		t[0]->beBuffed ## field(amount);				  \
	}

	/* real code */
	int power	 = c.getStatus()->getDamage();
	float factor = (power / 9999) * _value * a;
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

	bs[0] =
		new BuffSkill(51, "goodbuff", 10 * SECOND, 30, false, 0.3f, MyRGB(0,
																		  0,
																		  0),
					  damage);
}
