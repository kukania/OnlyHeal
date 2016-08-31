#pragma once
#include "Player.h"

void Player::equipSelectedItem(int index) {
	Item *temp = &(this->invetory[this->nowInventory].itemList[index]);
	this->invetory[this->nowInventory].equipedItemChange(index);
	this->getStatus()->setItemWithNum(*temp, temp->getType());
}