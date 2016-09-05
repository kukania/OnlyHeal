#pragma once
#include "cocos2d.h"
#include "parts/Tier.h"
#include"ui/CocosGUI.h"

USING_NS_CC;
class PartyLayer{
public:
	LayerGradient* content;
	void makePartyBtn(Tier t);
	ui::ScrollView *scrollView;
	ui::Button *cancelBtn;
	PartyLayer();
};