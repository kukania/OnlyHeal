#include "RangeSkill.h"
#include"../characters/Monster.h"
#include "../myUtility.h"

RangeSkill::RangeSkill()
	:Skill(9999, "UNKOWN_RANGE", 0, 1, range_atk, false) {
	_factor = 1.0f;
}
RangeSkill::RangeSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor)
	:Skill(ID, name, cooltime, time, range_atk, multi) {
	_factor = factor;
}
int RangeSkill::activate(Character **t, Character &c) {
	int power = c.getStatus()->getDamage();
	int amount = DAMAGE_FOMULA(c, t[1]);
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		((Monster*)t[0])->beAttacked(amount);
		c.getStatus()->addAgro(amount);
		//_sleep(1000);
	}
	return 0;
}