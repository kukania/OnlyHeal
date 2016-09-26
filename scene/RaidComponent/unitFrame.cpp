/* ============================================================
FileName:	UnitFrame.cpp
Revision:	2016/08/25 by PorcaM
Modified:	2016/09/23 by PorcaM
============================================================ */

#include "UnitFrame.h"
#include <cstdio>
#include <sstream>

#define LEFT_CENTER			Vec2 (0, 0.5f)
#define FONT_SDCRAYON 		"fonts/sdCrayon.ttf"
#define STR_RSC_PATH 		string("images/raid/")
#define GET_FIELD(field) 	getCharacter()->getStatus()->get##field()

UnitFrame::
UnitFrame (Character *character) {
	curRatio = 1.0f;
	setCharacter(character);
	initBackground ();
	initIcon ();
	initHP ();
	initDPS ();
}

/* ============================================================
1. Character
============================================================ */
Character*
UnitFrame::
getCharacter () {
	return _character;
}

void 
UnitFrame::
setCharacter (Character *character) {
	if (character == NULL) {
		printf ("Warning: This Frame assigned null character. \n");
	}
	_character = character;
	return;
}

/* ============================================================
2. Background
============================================================ */
void
UnitFrame::
initBackground (){
	string path = STR_RSC_PATH + "bg.png";
	_background = Sprite::create (path);
	_background->setAnchorPoint (LEFT_CENTER);
	this->addChild (_background, 0);
	return;
}

/* ============================================================
3. Icon
============================================================ */
void
UnitFrame::
initIcon (){
	_icon = Sprite::create (getIconPath ());
	_icon->setAnchorPoint (LEFT_CENTER);
	_icon->setPosition (Vec2 (5, 0));
	this->addChild (_icon, 1);
	return;
}

void 
UnitFrame::
updateIcon (){
	_icon->setTexture (getIconPath ());
	return;
}

/* ============================================================
4. HP
============================================================ */
void
UnitFrame::
initHP (){
	initHPLog ();
	initHPBar ();
	return; 
}

void 
UnitFrame::
updateHP (){
	updateHPLog ();
	updateHPBar ();
	return;
}

/* ============================================================
5. DPS
============================================================ */
void 
UnitFrame::
initDPS () {
	string 	text = getDpsString ();
	string 	font = FONT_SDCRAYON;
	int 	size = 24;
	_dpslog = Label::create (text, font, size);
	_dpslog->setAnchorPoint (Vec2 (1, 0));
	_dpslog->setPosition (Vec2 (240, -40));
	this->addChild (_dpslog, 4);
	return;
}

void 
UnitFrame::
updateDPS (){
	string 	text = getDpsString ();
	_dpslog->setString (text);
	return;
}

/* ============================================================
4-1. HP Log
============================================================ */
void
UnitFrame::
initHPLog (){
	string 	text = getHPRatioString ();
	string	font = FONT_SDCRAYON;
	int 	size = 24;
	_hplog = Label::create (text, font, size);
	_hplog->setAnchorPoint (LEFT_CENTER);
	_hplog->setPosition (Vec2 (80, 20));
	this->addChild (_hplog, 3);
	return;
}

void 
UnitFrame::
updateHPLog (){
	float test=(float)GET_FIELD(HP) / (float)GET_FIELD(MaxHP);
	string 	text = getHPRatioString ();
	_hplog->setString (text);
	//add effect
	if (curRatio > test) {
		curRatio = test;
		auto action = MoveBy::create(0.01,Vec2(5,0));
		auto action2 = MoveBy::create(0.01, Vec2(-5, 0));
		auto seq = Sequence::create(action, action2, NULL);
		this->runAction(seq);
	}
	return;
}

/* ============================================================
4-2. HP Bar
============================================================ */
void 
UnitFrame::
updateHPBar (){
	_hpbar->setScaleX (_hpRatio);
	return;
}

void
UnitFrame::
initHPBar (){
	string path = STR_RSC_PATH + "greenHP.png";
	_hpbar = Sprite::create (path);
	_hpbar->setAnchorPoint (LEFT_CENTER);
	_hpbar->setPosition (Vec2 (75, 20));
	_hpbar->setScaleX (_hpRatio);
	this->addChild (_hpbar, 2);
	return;
}

/* ============================================================
All
============================================================ */
void 
UnitFrame::
updateAll (){
	updateIcon ();
	updateHP ();
	updateDPS ();
	return;
}

/* ============================================================
Inner calculator functions
============================================================ */

string
UnitFrame::
f2s(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

string
UnitFrame::
getIconPath (){
	string type[4] = {"healer", "melee", "range", "tanker"};
	string path = STR_RSC_PATH + type[getCharacter ()->getType () - 1] + ".png";
	return path;
}

string
UnitFrame::
getDpsString (){
	int damage = GET_FIELD (Damage);
	return to_string (damage);
}

string
UnitFrame::
getHPRatioString (){
	int 	curHP = GET_FIELD (HP);
	int 	maxHP = GET_FIELD (MaxHP);
	float 	ratio = _hpRatio = (float)curHP / maxHP;
	string 	text = f2s(ratio * 100) + "%";
	return text;
}

#undef LEFT_CENTER
#undef FONT_SDCRAYON
#undef STR_RSC_PATH 			
#undef GET_FIELD(field) 	