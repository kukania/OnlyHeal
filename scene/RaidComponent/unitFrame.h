/*
FileName:	UnitFrame.h
Revision:	2016/08/25 by PorcaM
Modified:	2016/08/30 by PorcaM
*/

#pragma once

#include "cocos2d.h"
#include "characters\Character.h"
#include <string>
USING_NS_CC;

class UnitFrame : public Layer{
private: 
	Character	*_character;
	Sprite		*_background, *_icon, *_hpbar;
	Label		*_hplog, *_dpslog;
public:
	UnitFrame(Character *);
	Character *getCharacter();
	void setCharacter(Character *);
	void setBackground(string);
	void setIcon(string);
	void setHP();
	void setDPS();
};