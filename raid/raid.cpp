#include "raid.h"

Raid::Raid(Character _user) {
	list[0] = _user;
	Tier base = _user.getStatus()->evalTier();
	list[1] = Monster(base);
	list[2] = TankNPC(base, 2);
	list[3] = MeleeNPC(base, 3);
	list[4] = MeleeNPC(base, 4);
	list[5] = RangeNPC(base, 5);
}