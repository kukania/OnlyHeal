/*
FileName:	UnitFrame.cpp
Revision:	2016/08/25 by PorcaM
*/

#include "UnitFrame.h"
#include <cstdio>

UnitFrame::UnitFrame(Character *character) {
	setCharacter(character);
	setBackground("plate.png");
	setIcon("melee.png");
	setHP();
	setDPS();
	this->addChild(_background, 0);
	this->addChild(_icon, 1);
	this->addChild(_hp, 2);
	this->addChild(_dps, 3);
}
Character *UnitFrame::getCharacter() {
	return _character;
}
void UnitFrame::setCharacter(Character *character) {
	if (character == NULL) {
		printf("Warning: This Frame assigned null character. \n");
	}
	_character = character;
	return;
}
void UnitFrame::setBackground(string path) {
	_background = Sprite::create(path);
	_background->setScale(2.0f);

	return;
}
void UnitFrame::setIcon(string path) {
	_icon = Sprite::create(path);
	_icon->setScale(0.1f);
	return;
}
void UnitFrame::setHP() {
	_hp = Label::create("fuuuuuuuuk", "fonts/arial", 12);
	return;
}
void UnitFrame::setDPS() {
	_dps = Label::create("fuuuuuuuuk", "fonts/arial", 12);
	return;
}