#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"../parts/Item.h"
#include<string>
USING_NS_CC;

class ItemComponent{
public:
	Layer *content;
	ui::Button * btn;
	Sprite *spr;
	ItemComponent(Item*,Size size);
	void setNew();
	void setEquiped();
private:
	Size size;
};