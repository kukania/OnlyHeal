#pragma once
#include "Character.h"
#include "../parts/Inventory.h"
#include "../parts/Tier.h"

class Player :public Character {
public:
	Inventory inventory[3];
	Player(){ 
		inventory[WEAPON].type = WEAPON;
		inventory[WEAPON].equiped = NULL;
		inventory[ARMOR].type = ARMOR;
		inventory[ARMOR].equiped = NULL;
		inventory[ARTIFACT].type = ARTIFACT;
		inventory[ARTIFACT].equiped = NULL;
	}
	void equipSelectedItem(int index,int type);
};