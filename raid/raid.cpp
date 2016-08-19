#include "raid.h"

Raid::Raid(Character _user) {
	list = new Character[6];
	list[0] = _user;
	Tier base = _user.getStatus()->evalTier();
	list[1] = Monster(base);
	list[2] = TankNPC(base, 2);
	list[3] = MeleeNPC(base, 3);
	list[4] = MeleeNPC(base, 4);
	list[5] = RangeNPC(base, 5);
}
void Raid::printInfo() {
	for (int i = 0; i < 6; i++) {
		Status *temp = list[i].getStatus();
		printf("Agro: %d\nDamage: %d\nDefence: %d\nHP: %d, MaxHP: %d\nRDa: %d, RDe: %d\nSpeed: %f\n",
			temp->getAgro(), temp->getDamage(), temp->getDefence(),
			temp->getHP(), temp->getMaxHP(), temp->getMyRGBDamage(),
			temp->getMyRGBDefence(), temp->getSpeed());
	}
}