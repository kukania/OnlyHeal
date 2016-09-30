#include"consumableInventory.h"

void ConsumableInventory::pushConsumable(Consumable* input) {
	input->it = consumableList.end();
	this->consumableList.insert(consumableList.end(),input);
}
void ConsumableInventory::useConsumable(Consumable* input) {
	input->consume();
	deleteConsumable(input);
}
void ConsumableInventory::deleteConsumable(Consumable* input) {
	this->consumableList.erase(input->it);
}