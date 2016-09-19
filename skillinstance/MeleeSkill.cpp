#include "MeleeSkill.h"
#include "myUtility.h"

MeleeSkill::MeleeSkill()
	:Skill(9999, "UNKOWN_MELEE", 0, 1, melee_atk, false) {
	_factor = 1.0f;
}
MeleeSkill::MeleeSkill(SkillID ID, string name, time_ms cooltime, time_s time, bool multi, float factor)
	:Skill(ID, name, cooltime, time, melee_atk, multi) {
	_factor = factor;
}
int MeleeSkill::activate(Character **t, Character &c) {
	int power = c.getStatus()->getDamage();
	int amount = DAMAGE_FOMULA(c, t[1]);
	setCooldown();
	for (int i = 0; i < getTime(); i++) {
		t[1]->beAttacked(amount);
		c.getStatus()->addAgro(amount);
		//_sleep(1000);
	}
	return 0;
}
