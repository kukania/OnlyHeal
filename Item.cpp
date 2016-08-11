#include "Item.h"
#include "Tier.h"

Item::Item() {
	Tier temp = Tier(1);
	Item(temp, 0, RGB());
}
Item::Item(Tier _tier, int _type, RGB _rgb) {
	setTier(_tier);
	setType(_type);
	setRGB(_rgb);
}

void Item::setTier(Tier _tier) {
	tier = _tier;
}
void Item::setType(int _type) {
	type = type;
}
void Item::setRGB(RGB _rgb) {
	rgb = _rgb;
}

Tier Item::getTier() {
	return tier;
}
int Item::getType() {
	return type;
}
RGB Item::getRGB() {
	return rgb;
}