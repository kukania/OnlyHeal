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
		inventory[Item::TYPE::WEAPON].type = Item::TYPE::WEAPON;
		inventory[Item::TYPE::WEAPON].equiped = NULL;
		inventory[Item::TYPE::ARMOR].type = Item::TYPE::ARMOR;
		inventory[Item::TYPE::ARMOR].equiped = NULL;
		inventory[Item::TYPE::ARTIFACT].type = Item::TYPE::ARTIFACT;
		inventory[Item::TYPE::ARTIFACT].equiped = NULL;
		skillPoint = 0;
	}
	void equipSelectedItem(int index,int type);
	virtual void	initSkillSet(int);
	int skilltreeData[3] = { 0 };
};