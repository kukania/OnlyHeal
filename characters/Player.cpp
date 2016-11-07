/*
FileName:	Player.cpp
Revision:	? by Kukania
Modified:	2016/09/07 by PorcaM
*/

#pragma once
#include "Player.h"

void Player::equipSelectedItem(int index,int itemtype) {
	Item *temp = &(this->inventory[itemtype].itemList[index]);
	this->inventory[itemtype].equipedItemChange(index);
	this->inventory[itemtype].equipedNum = index;
	this->getStatus()->setItemWithNum(*temp, temp->getType());
}
void	Player::initSkillSet(int skillnum) {
	return;
}