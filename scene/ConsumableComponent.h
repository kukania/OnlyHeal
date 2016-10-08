#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"../parts/consumableItem.h"
#include"HelloWorldComponent/ConsumableLayer.h"
USING_NS_CC;
class ConsumableComponent {
public:
	ConsumableComponent(Size,Consumable *);
	static ConsumableComponent* createRandomConsumable(Size s);
	void addedTo(Node *p);
	void addedTo(Node *p,Point sp);
	void setPosition(Point);
	void setCLayer(ConsumableLayer *);
	Consumable* getConsumable();
	ui::Button * container;
private:
	Consumable * item;
	ConsumableLayer* cLayer;
};