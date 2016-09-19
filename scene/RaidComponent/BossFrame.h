/*
FileName:	BossFrame.h
Revision:	2016/08/29 by PorcaM
*/

#pragma once
#include "cocos2d.h"
#include "characters\Character.h"
#include <string>
USING_NS_CC;

class BossFrame : public Layer {
private:
	Character	*_character;
	Sprite		*_icon, *_hpbar, *_rgbbg;
	Label		*_hplog, *_damagelog, *_rgblog;
public:
	BossFrame(Character *);
	void setCharacter(Character *);
	void initIcon();
	void initHP();
	void initRGB();
	void initDamage();
};