#pragma once
#include "Tier.h"
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
	return 0;
}