#pragma once
#include "Item.h"
#include<vector>
class Inventory{
public :
	int type;
	int equipedNum;
	Item *equiped;
	std::vector<Item> itemList;
	void pushItemList(Item a);
	void deleteItemList(int index);
	void equipedItemChange(int index);
	void sortItemList();
	static bool sortFunction(Item a, Item b);
	void readFile();
	void saveFile();/*FTYPE TYPE SIZE LIST EQUIPEDNUM*/
};