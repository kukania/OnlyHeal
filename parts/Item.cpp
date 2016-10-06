#include "Item.h"
#include "Tier.h"

Item::Item() {
	Tier temp = Tier(1);
	Item(temp, 0, MyRGB());
}
Item::Item(Tier _tier, int _type, MyRGB _rgb) {
	setTier(_tier);
	setType(_type);
	setMyRGB(_rgb);
}
void Item::setTier(Tier _tier) {
	tier = _tier;
}
void Item::setType(int _type) {
	type = _type;
}
void Item::setMyRGB(MyRGB _rgb) {
	rgb = _rgb;
}

Tier Item::getTier() {
	return tier;
}
int Item::getType() {
	return type;
}
MyRGB Item::getMyRGB() {
	return rgb;
}
string Item::toString() {
	string str = "";
	str += "등급: \n";
	str += this->tier.getTierByString() + "\n";
	str += "타입: ";
	switch (this->type) {
	case WEAPON:
		str += "무기";
		break;
	case ARMOR:
		str += "방어구";
		break;
	case ARTIFACT:
		str += "장신구";
		break;
	}
	str += "\n";
	char tempValue[20];
	itoa(this->tier.getValue(), tempValue,10);
	str += "값: ";
	for (int i = 0; tempValue[i] != NULL; i++) {
		str.push_back(tempValue[i]);
	}
	str += "\n";
	return str;
}
