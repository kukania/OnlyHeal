#pragma once
#include <list>
#include"consumableItem.h"
class ConsumableInventory{
public:
	bool checkChange;
	std::list<Consumable *> consumableList;
	void pushConsumable(Consumable*);
	void useConsumable(Consumable*);
	void deleteConsumable(Consumable*);
};