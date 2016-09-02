#pragma once
#include "Player.h"

void Player::equipSelectedItem(int index,int itemtype) {
	Item *temp = &(this->inventory[itemtype].itemList[index]);
	this->inventory[itemtype].equipedItemChange(index);
	this->getStatus()->setItemWithNum(*temp, temp->getType());
}