#pragma once
#include <list>
#include"../characters/Character.h"
#include"consumableItem.h"
class ConsumableInventory{
public:
	bool checkChange;
	std::list<Consumable *> consumableList;
	void pushConsumable(Consumable*);
	void useConsumable(Consumable*);
	void deleteConsumable(Consumable*);
	void saveFile();/*FTYPE CHECKCHANGE LIST*/
	void readFile(Character *owner);
};