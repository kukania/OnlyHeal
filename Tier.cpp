#pragma once
#include "Tier.h"
#include <random>
Tier::Tier(short input) {
	setLevel(input);
}
Tier::Tier(short *input){
	setLevel(input);
}
short Tier::setLabel(short input) {
	Tier::level2label(input, this->label);
	this->level = input;
	setValue();
}
short Tier::setLevel(short *input) {
	this->level = Tier::label2level(input);
	for (int i = 0; i < 4; i++)label[i] = input[i];
	setValue();
}
short Tier::setLevel(short input) {
	level = input;
	Tier::level2label(input, label);
	setValue();
}
short Tier::getLevel() { return level; }
short Tier::setLabel(short *input) {
	for (int i = 0; i < 4; i++)label[i] = input[i];
	level = Tier::label2level(input);
	setValue();
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