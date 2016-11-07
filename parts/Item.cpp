#include "Item.h"
#include "Tier.h"
#include"../FileOperation.h"
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
	str += "���: \n";
	str += this->tier.getTierByString() + "\n";
	str += "Ÿ��: ";
	switch (this->type) {
	case WEAPON:
		str += "����";
		break;
	case ARMOR:
		str += "��";
		break;
	case ARTIFACT:
		str += "��ű�";
		break;
	}
	str += "\n";
	char tempValue[20];
	itoa(this->tier.getValue(), tempValue,10);
	str += "��: ";
	for (int i = 0; tempValue[i] != NULL; i++) {
		str.push_back(tempValue[i]);
	}
	str += "\n";
	return str;
}
/*FTYPE type isNew TIER MYRGB*/
string Item::getFileString() {
	char buf[256];
	sprintf(buf, "%d %d %d\n%s%s", FileOperation::FTYPE::ITEM,this->type, 
		isNew ? 1:0, this->tier.getFileString().c_str(), this->rgb.getFileString().c_str());
	return string(buf);
}
Item Item::itemByString(std::string fstring[]) {
	int ftype, type, isNew;
	sscanf(fstring[0].c_str(), "%d %d %d\n", &ftype, &type, &isNew);
	MyRGB tempRGB = MyRGB::myRGBByString(fstring[2]);
	Tier tempTier = Tier::tierByString(fstring[1]);
	Item res;
	res.setTier(tempTier);
	res.setMyRGB(tempRGB);
	res.type = type;
	res.isNew = isNew;
	return res;
}