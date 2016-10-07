/* ==================================================
FileName:	Player.h
Revision:	? by Kukania
Modified:	2016/10/05 by PorcaM
================================================== */

#pragma once
#include "Character.h"
#include "../parts/Inventory.h"
#include"../parts/consumableInventory.h"
#include "../parts/Tier.h"

/* ==================================================
	Modified: 2016/10/05 by PorcaM
================================================== */
class Player :public Character {
public:
	int skillPoint;
	Inventory inventory[3];
	ConsumableInventory cInventory;
	Player(){ 
		inventory[WEAPON].type = WEAPON;
		inventory[WEAPON].equiped = NULL;
		inventory[ARMOR].type = ARMOR;
		inventory[ARMOR].equiped = NULL;
		inventory[ARTIFACT].type = ARTIFACT;
		inventory[ARTIFACT].equiped = NULL;
		skillPoint = 0;
	}
	void equipSelectedItem(int index,int type);
	virtual void	initSkillSet(int);
	int skilltreeData[3] = { 0 };
};