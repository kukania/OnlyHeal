#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include"ui/CocosGUI.h"
#include "../characters/Player.h"
#include"../parts/consumableItem.h"
#include "cocos2d.h"
#include"../parts/consumableInventory.h"
USING_NS_CC;
class ConsumableLayer{
public:
	ConsumableLayer(Size,ConsumableInventory *,int,int);
	void reloadData();
	void addedTo(Node *);
private:
	ui::ScrollView* scv;
	Size contentsSize;
	int column;
	int cellHeight;
	int cellWidth;
	Layer* content;
	ConsumableInventory *inven;
};