#include"../characters/Player.h"
#include"../FileOperation.h"
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
	((Player*)owner)->cInventory.deleteConsumable(*this->it);
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

string Consumable::getFileString() {
	char buf[512];
	sprintf(buf, "%d %d %d %s %s\n", FileOperation::FTYPE::CONSUMABLEITEM, this->type, this->value,this->name.c_str(),this->contents.c_str());
	return string(buf);
}
Consumable* Consumable::consumableByString(Character *owner,string fstring) {
	int ftype, type, value;
	char name[100];
	char contents[100];
	sscanf(fstring.c_str(), "%d %d %d %s %s\n", &ftype, &type, &value,name,contents);
	return new Consumable(owner,(Consumable::CType)type, value,name,contents);
}