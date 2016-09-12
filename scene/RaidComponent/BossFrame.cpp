/*
FileName:	BossFrame.cpp
Revision:	2016/08/29 by PorcaM
Modified:	2016/08/30 by PorcaM
*/

#include "BossFrame.h"

BossFrame::BossFrame(Character *character) {
	_character = character;
	initIcon();
	initHP();
	initRGB();
	initDamage();
}

void BossFrame::setCharacter(Character *character) {
	if (character == NULL) {
		printf("Warning: This Frame assigned null character. \n");
	}
	_character = character;
	return;
}

void BossFrame::initIcon() {
	string _path = "images/icon/monster.png";
	_icon = Sprite::create(_path);
	_icon->setName("icon");
	_icon->setPosition(Vec2(0, 0));
	this->addChild(_icon);
	return;
}

void BossFrame::initHP() {
	string _path = "images/redHP.png";
	_hpbar = Sprite::create(_path);
	_hpbar->setName("hpbar");
	_hpbar->setPosition(Vec2(0, -100));
	this->addChild(_hpbar);
	return;
}

void BossFrame::initRGB() {
	Layer *rgbLayer = Layer::create();
	string _path = "images/plate2.png";
	_rgbbg = Sprite::create(_path);
	_rgbbg->setPosition(Vec2(0, 0));
	rgbLayer->addChild(_rgbbg);
#define GET_RGB_STRING(it) std::to_string(_character->getStatus()->getMyRGBDamage().get##it())
	string _data = GET_RGB_STRING(R) + "\n" + GET_RGB_STRING(G) + "\n" + GET_RGB_STRING(B);
#undef	GET_RGB_STRING
	_rgblog = Label::create(_data, "fonts/sdCrayon.ttf", 24);
	rgbLayer->addChild(_rgblog);
	rgbLayer->setPosition(Vec2(-120, 20));
	this->addChild(rgbLayer);
	return;
}

void BossFrame::initDamage() {
	string _data = "1234";
	_damagelog = Label::create(_data, "fonts/sdCrayon.ttf", 24);
	_damagelog->setColor(Color3B(255, 125, 0));
	_damagelog->setPosition(Vec2(110, 0));
	this-> addChild(_damagelog, 10);
	return;
}