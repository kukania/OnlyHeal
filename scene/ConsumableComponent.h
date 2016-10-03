#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"../parts/consumableItem.h"
#include"../scene/ConsumableLayer.h"
USING_NS_CC;
class ConsumableComponent {
public:
	ConsumableComponent(Size,ConsumableLayer * ,Consumable *);
	void addedTo(Node *p);
	void setPosition(Point);
	void setCLayer(ConsumableLayer *);
private:
	ui::Button * container;
	Consumable * item;
	ConsumableLayer* cLayer;
};