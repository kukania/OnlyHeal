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
	Sprite*		_icon;
	Sprite*		_hpbar;
	Label*		_hplog;
	Label*		_dpslog;
	float 		_hpRatio;
	float		curRatio;
	void 		initBackground ();
	void 		initIcon ();
	void 		initHPBar ();
	void 		initHPLog ();
	void 		initHP ();
	void 		initDPS ();
	void 		updateHPBar ();
	void 		updateHPLog ();
	string		f2s (float);
	string 		getIconPath ();
	string 		getDpsString ();
	string 		getHPRatioString ();
public:
	Sprite*		_background;
	UnitFrame (Character *);
	Character* 	getCharacter ();
	void 		setCharacter (Character *);
	void 		updateIcon ();
	void 		updateHP ();
	void 		updateDPS ();
	void 		updateAll ();
	~UnitFrame() {
		CCLOG("UNIT frame remove");
		this->autorelease();
	}
};