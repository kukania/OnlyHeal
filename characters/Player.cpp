#pragma once
#include "Player.h"

void Player::equipSelectedItem(int index) {
	Item *temp = &(this->inventory[this->nowInventory].itemList[index]);
	this->inventory[this->nowInventory].equipedItemChange(index);
	this->getStatus()->setItemWithNum(*temp, temp->getType());
}