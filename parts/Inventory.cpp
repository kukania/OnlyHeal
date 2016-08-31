#pragma once
#include"Inventory.h"
#include<algorithm>


void Inventory::pushItemList(Item a) {
	this->itemList.push_back(a);
}
void Inventory::deleteItemList(int index) {
	vector<Item>::iterator it = this->itemList.begin();
	for (int i = 0; i < index; i++) { it++; }
	this->itemList.erase(it,it);
}
void Inventory::equipedItemChange(int index) {
	equiped = &itemList[index];
}
void Inventory::sortItemList() {
	std::sort(itemList.begin(), itemList.end(), this->sortFunction);
}
bool Inventory::sortFunction(Item a, Item b) {
	return a.getTier().getLevel() > b.getTier().getLevel();
}