#pragma once
#include "Character.h"

int Character::beAttacked(int damage) {
	myStatus.addHP(-damage);
	if (myStatus.getHP() == 0)
		isDie = true;
}
int Character::doAttack() {
	list<Skill*>::iterator it = mySkillSet.begin();
	for(int i=0; it!=mySkillSet.end(); it++){
		
	}
}
bool Character::checkDie() {
	return isDie;
}