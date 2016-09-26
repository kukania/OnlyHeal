/* ============================================================
FileName:	BossFrame.h
Revision:	2016/08/29 by PorcaM
Modified: 	2016/09/26 by PorcaM
============================================================ */

#pragma once

#include <string>

#include "cocos2d.h"
#include "characters\Character.h"
USING_NS_CC;

class BossFrame : public Layer {
 public:
 	BossFrame (Character*);
 	void 	setCharacter (Character*);
 	void 	initIcon ();
	void 	initHP ();
	void 	initRGB ();
	void 	initDamage ();
	void 	updateAll ();
 private:
 	Character 	*_character;
	Sprite 		*_icon;	
 	Sprite 		*_hpbar;
 	Sprite 		*_rgbbg;
 	Label 		*_hplog;
 	Label 		*_damagelog;
 	Label 		*_rgblog;
};