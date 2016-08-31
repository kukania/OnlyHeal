#pragma once
#include "Character.h"
#include "../parts/Inventory.h"
#include "../parts/Tier.h"
enum inventory {
	CHA,RAC,TER
};
class Player :public Character {
public:
	Inventory invetory[3];
	Player(Tier a) :Character(a){}
};