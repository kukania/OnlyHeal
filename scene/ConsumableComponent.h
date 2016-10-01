#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"../parts/consumableItem.h"
USING_NS_CC;
class ConsumableComponent {
public:
	ConsumableComponent(Size,Consumable *);
	void addedTo(Node *p);
	void setPosition(Point);
private:
	ui::Button * container;
	Consumable * item;
};