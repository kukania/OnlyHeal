/* ============================================================
FileName:	UnitFrame.cpp
Revision:	2016/08/25 by PorcaM
Modified:	2016/09/23 by PorcaM
============================================================ */

#include "UnitFrame.h"
#include <cstdio>
#include <sstream>

#define ANCHOR_LEFT_CENTER	Vec2 (0, 0.5f)
#define FONT_SDCRAYON 		"fonts/sdCrayon.ttf"

std::string 
f2s(float number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

UnitFrame::
UnitFrame (Character *character) {
	setCharacter(character);
	initBackground ();
	initIcon ();
	initHP ();
	initDPS ();
}

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

void
UnitFrame::
initBackground (){
	string path = "images/raid/bg.png";
	_background = Sprite::create (path);
	_background->setAnchorPoint (ANCHOR_LEFT_CENTER);
	this->addChild (_background, 0);
	return;
}

void
UnitFrame::
initIcon (){
	_icon = Sprite::create (getIconPath ());
	_icon->setAnchorPoint (ANCHOR_LEFT_CENTER);
	_icon->setPosition (Vec2 (5, 0));
	this->addChild (_icon, 1);
	return;
}

void
UnitFrame::
initHPBar (){
	string path = "images/raid/greenHP.png";
	_hpbar = Sprite::create (path);
	_hpbar->setAnchorPoint (ANCHOR_LEFT_CENTER);
	_hpbar->setPosition (Vec2 (75, 20));
	this->addChild (_hpbar, 2);
	return;
}

void
UnitFrame::
initHPLog (){
	int 	curHP = getCharacter ()->getStatus ()->getHP ();
	int 	maxHP = getCharacter ()->getStatus ()->getMaxHP ();
	float 	ratio = (float)curHP / maxHP;
	string 	text = f2s(_ratio * 100) + "%";
	string	font = FONT_SDCRAYON;
	int 	size = 24;
	_hplog = Label::create (text, font, size);
	_hplog->setAnchorPoint (ANCHOR_LEFT_CENTER);
	_hplog->setPosition (Vec2 (80, 20));
	this->addChild (_hplog, 3);
	return;
}

void
UnitFrame::
initHP (){
	initHPBar ();
	initHPLog ();
	return; 
}

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
updateIcon (){
	_icon->setTexture (getIconPath ());
	return;
}

void 
UnitFrame::
updateHP (){
	_icon->setTexture (getIconPath ());
	return;
}

void 
UnitFrame::
updateDPS (){
	string 	text = getDpsString ();
	_dpslog->setString (text);
	return;
}

void 
UnitFrame::
updateAll (){
	updateIcon ();
	updateHP ();
	updateDPS ();
	return;
}

string
UnitFrame::
getIconPath (){
	string type[4] = {"healer", "melee", "range", "tanker"};
	string path = "images/raid/" + type[getCharacter ()->getType () - 1] + ".png";
	return path;
}

string
UnitFrame::
getDpsString (){
	int damage = getCharacter ()->getStatus ()->getDamage ();
	return to_string (damage);
}

#undef ANCHOR_LEFT_CENTER
#undef FONT_SDCRAYON