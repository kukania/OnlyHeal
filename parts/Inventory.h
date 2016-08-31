#pragma once
#include "Item.h"
#include<vector>
class Inventory{
public :
	int type;
	Item *equiped;
	std::vector<Item> itemList;
	void pushItemList(Item a);
	void deleteItemList(int index);
	void equipedItemChange(int index);
	void sortItemList();
	bool sortFunction(Item a, Item b);
};