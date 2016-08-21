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

	for (int i = 0; i < 6; i++) {
		list[i].setCharacterList(list);
	}
}
void Raid::printInfo() {
	printf("============PRINT INFO==========\n");
	for (int i = 0; i < 6; i++) {
		Status *temp = list[i].getStatus();
		printf("NUMBER: %d\n", i);
		printf("Agro: %d, Speed: %f\nDamage: %d\nDefence: %d\nHP: %d, MaxHP: %d\n",
			temp->getAgro(), temp->getSpeed(), (int)temp->getDamage(), (int)temp->getDefence(),
			(int)temp->getHP(), (int)temp->getMaxHP());
	}
	return;
}
void Raid::battle() {
	bool end = false;
	printInfo();
	return;
}