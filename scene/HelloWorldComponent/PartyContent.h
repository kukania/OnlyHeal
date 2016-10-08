#pragma once
#include"../../parts/Tier.h"
#include"../../characters/Character.h"
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include<string>
USING_NS_CC;
class PartyContent {
public:
	bool selected;
	DrawNode * backGround;
	ui::Button *content;
	ui::Scale9Sprite *img[6];
	Character *list[6];
	std::string getStringContent();
	PartyContent(Tier t,Character *p);
	~PartyContent() {
		for (int i = 0; i < 6; i++) delete img[i];
		delete content;
	}
};