#pragma once
#include <list>
#include"consumableItem.h"
class ConsumableInventory{
public:
	std::list<Consumable *> consumableList;
	void pushConsumable(Consumable*);
	void useConsumable(Consumable*);
	void deleteConsumable(Consumable*);
};