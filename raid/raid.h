#pragma once

#include "..\characters\Character.h"
#include "..\characters\Monster.h"
#include "..\characters\TankNPC.h"
#include "..\characters\MeleeNPC.h"
#include "..\characters\RangeNPC.h"

class Raid {
private:
	//Character *list;
public:
	Character *list;
	Raid(Character);
	void printInfo();
	void battle();
};