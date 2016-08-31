#pragma once
#include "Character.h"
#include "../parts/Inventory.h"
#include "../parts/Tier.h"

class Player :public Character {
public:
	int nowInventory;
	Inventory invetory[3];
	Player(Tier a) :Character(a) { this->setType(CharacterType::healer); }
	void equipSelectedItem(int index);
};