/* ============================================================
FileName:	BossFrame.cpp
Revision:	2016/08/29 by PorcaM
Modified:	2016/09/26 by PorcaM
============================================================ */

#include "BossFrame.h"

#include <string>

#define GET_FIELD(field) 	getCharacter()->getStatus()->get##field()
#define GET_RGB_STRING(it) std::to_string(_character->getStatus()->getMyRGBDamage().get##it())

BossFrame::BossFrame(Character *character) {
	_character = character;
	initIcon();
	initHP();
	initRGB();
	initDamage();
}

Character*
BossFrame::
getCharacter() {
	return _character;
}

void BossFrame::setCharacter(Character *character) {
	if (character == NULL) {
		printf("Warning: This Frame assigned null character. \n");
	}
	_character = character;
	return;
}

void BossFrame::initIcon() {
	string _path = "images/raid/monster.png";
	_icon = Sprite::create(_path);
	_icon->setName("icon");
	_icon->setPosition(Vec2(0, 0));
	this->addChild(_icon);

	return;
}

void BossFrame::initHP() {
	string _path = "images/raid/redHP.png";
	_tempRatio = 1.0f;
	_hpbar = Sprite::create(_path);
	_hpbar->setName("hpbar");
	_hpbar->setPosition(Vec2(-172, -100));
	_hpbar->setAnchorPoint (Vec2 (0, 0.5));
	this->addChild(_hpbar);
	return;
}

void BossFrame::initRGB() {
	Layer *rgbLayer = Layer::create();
	string _path = "images/raid/plate2.png";
	_rgbbg = Sprite::create(_path);
	_rgbbg->setPosition(Vec2(0, 0));
	rgbLayer->addChild(_rgbbg);
	string _data = GET_RGB_STRING(R) + "\n" + GET_RGB_STRING(G) + "\n" + GET_RGB_STRING(B);
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

// Not totally
void
BossFrame::
updateAll (){
	int 	curHP = GET_FIELD (HP);
	int 	maxHP = GET_FIELD (MaxHP);
	_hpRatio = (float)curHP / maxHP;
	if (_tempRatio > _hpRatio) {
		_tempRatio = _hpRatio;
		auto action1 = MoveBy::create(0.02f, Vec2(0, 10));
		auto action2 = MoveBy::create(0.02f, Vec2(0, -10));
		auto _action = Sequence::create(action1, action2, NULL);
		_icon->runAction(_action);
	}
	_hpbar->setScaleX (_hpRatio);
	string text = GET_RGB_STRING(R) + "\n" + GET_RGB_STRING(G) + "\n" + GET_RGB_STRING(B);
	_rgblog->setString (text);
	return;
}

#undef GET_FIELD
#undef GET_RGB_STRING