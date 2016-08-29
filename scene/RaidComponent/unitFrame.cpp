/*
FileName:	UnitFrame.cpp
Revision:	2016/08/25 by PorcaM
Modified:	2016/08/29 by PorcaM
*/

#include "UnitFrame.h"
#include <cstdio>
#include <sstream>

std::string f2s(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

UnitFrame::UnitFrame(Character *character) {
	setCharacter(character);
	setBackground("images/bg.png");
	setIcon("images/icon/");
	setHP();
	setDPS();
	this->addChild(_background, 0);
	this->addChild(_icon, 1);
	this->addChild(_hpbar, 2);
	this->addChild(_hplog, 3);
	this->addChild(_dpslog, 4);
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
	_background->setScale(1.0f);
	_background->setAnchorPoint(Vec2(0, 0.5f));
	return;
}
void UnitFrame::setIcon(string path) {
	string postfix[4]	= { "healer", "melee", "range", "tanker" };
	string _path		= path + postfix[_character->getType()] + ".png";
	_icon = Sprite::create(_path);
	_icon->setScale(1.0f);
	_icon->setAnchorPoint(Vec2(0, 0.5f));
	_icon->setPosition(Vec2(5, 0));
	return;
}
void UnitFrame::setHP() {
	_hpbar = Sprite::create("images/greenHP.png");
	_hpbar->setScale(1.0f);
	_hpbar->setAnchorPoint(Vec2(0, 0.5f));
	_hpbar->setPosition(Vec2(75, 20));
	float _hp = _character->getStatus()->getHP()/_character->getStatus()->getMaxHP();
	_hplog = Label::create(f2s(_hp*100)+"%", "fonts/arial.ttf", 24);
	_hplog->setAnchorPoint(Vec2(0, 0.5f));
	_hplog->setPosition(Vec2(80, 20));
	return;
}
void UnitFrame::setDPS() {
	_dpslog = Label::create("700k", "fonts/arial.ttf", 36);
	_dpslog->setAnchorPoint(Vec2(1, 0));
	_dpslog->setPosition(Vec2(240, -40));
	return;
}