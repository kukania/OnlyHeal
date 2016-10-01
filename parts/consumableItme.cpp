#include"../characters/Player.h"
#include"consumableItem.h"
Consumable::Consumable(Character * owner, CType type, int value,string name, string contents) {
	this->owner = owner;
	this->type = type;
	this->name = name;
	this->contents = contents;
	this->value = value;
}

Consumable::Consumable(Character * owner, CType type, int value) {
	this->owner = owner;
	this->type = type;
	this->value = value;
	this->name = "???";
	this->contents = "???";
}
void Consumable::consume() {
	switch (this->type) {
	case MAXHP:
		owner->getStatus()->addMaxHPDefault(value);
		break;
	case DAMAGE:
		owner->getStatus()->addPureDamage(value);
		break;
	case DEFENCE:
		owner->getStatus()->addPureDefence(value);
		break;
	case SP:
		//try{
			((Player*)owner)->skillPoint += value;
		//}
		//catch(){
		//	break;
		//}
		break;
	}
}
string Consumable::toString() {
	string str = "템명 :" + this->name;
	str += "\n설명 :" + this->contents;
	return str;
}
void Consumable::setName(string name) {
	this->name = name;
}
void Consumable::setContent(string contents) {
	this->contents = contents;
}
void Consumable::setOwner(Character * owner) {
	this->owner = owner;
}
Consumable::CType Consumable::getType() {
	return this->type;
}
