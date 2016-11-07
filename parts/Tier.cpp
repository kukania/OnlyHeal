#pragma once
#include "Tier.h"
#include"../FileOperation.h"
#include <random>


Tier::Tier(short input) {
	setLevel(input);
}
Tier::Tier(short *input){
	setLabel(input);
}
short Tier::setLevel(short input) {
	if (input > MAX_LEVEL) input = MAX_LEVEL;
	level = input;
	Tier::level2label(input, label);
	setValue();
	return 0;
}
short Tier::getLevel() { return level; }
short Tier::setLabel(short *input) {
	for (int i = 0; i < 4; i++) {
		if (input[i] > MAX_LABEL) input[i] = MAX_LABEL;
		label[i] = input[i];
	}
	level = Tier::label2level(input);
	setValue();
	return 0;
}
short* Tier::getLabel() { return label; }

int Tier::getValue() {
	return value;
}

int Tier::setValue() {
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		temp *= 10;
		temp += label[3-i] * 3 + (rand() % 3) + 1;
	}
	value = temp;
	return 0;
}
std::string Tier::getTierByString() {
	std::string a;
	for (int i = 3; i >=0; i--) {
		switch (label[i]) {
		case 0:
			a += "Å·";
			break;
		case 1:
			a += "¿¥";
			break;
		case 2:
			a += "°«";
			break;
		}
		if (i == 2)
			a += "\n";
	}
	return a;
}

std::string Tier::getFileString() {
	char buf[100];
	sprintf(buf, "%d %d %d\n", FileOperation::TIER, this->getValue(), this->getLevel());
	return std::string(buf);
}

Tier Tier::tierByString(std::string fstring) {
	int ftype, value,level;
	sscanf(fstring.c_str(), "%d %d %d\n", &ftype, &value, &level);
	Tier res(level);
	res.value = value;
	return res;
}