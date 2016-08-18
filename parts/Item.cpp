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