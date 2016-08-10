#include "Item.h"

Item::Item() {
	Item("ŷŷŷŷ", 0, RGB());
}
Item::Item(string _tier, int _type, RGB _rgb) {
	setTier(_tier);
	setType(_type);
	setValue(_tier);
	setRGB(_rgb);
}

void Item::setTier(string _tier) {
	if (_tier.length != 4) {
		printf("Tier is not 4 levels.\n");
		return;
	}
	tier = _tier;
}
void Item::setType(int _type) {
	type = type;
}
void Item::setValue(string _tier) {
	int temp = 0;
	for (int i = 0; i < 4; i++) {

	}
}