/* ============================================================
FileName:	UnitFrame.h
Revision:	2016/08/25 by PorcaM
Modified:	2016/09/23 by PorcaM
============================================================ */

#pragma once

#include "cocos2d.h"
#include "characters\Character.h"
#include <string>
USING_NS_CC;

class UnitFrame : public CCNode{
private: 
	Character*	_character;
	Sprite*		_background;
	Sprite*		_icon;
	Sprite*		_hpbar;
	Label*		_hplog;
	Label*		_dpslog;
	void 		initIcon ();
	void 		initHP ();
	void 		initDPS ();
public:
	UnitFrame (Character *);
	Character* 	getCharacter ();
	void 		setCharacter (Character *);
	void 		setBackground (string);
	void 		setIcon (string);
	void 		setHP ();
	void 		setDPS ();
};