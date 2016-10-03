#include"consumableInventory.h"

void ConsumableInventory::pushConsumable(Consumable* input) {
	input->it=this->consumableList.insert(consumableList.end(),input);
}
void ConsumableInventory::useConsumable(Consumable* input) {
	input->consume();
	deleteConsumable(input);
}
void ConsumableInventory::deleteConsumable(Consumable* input) {
	this->checkChange = true;
	this->consumableList.erase(input->it);
}