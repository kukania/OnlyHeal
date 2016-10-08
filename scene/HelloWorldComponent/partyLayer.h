#pragma once
#include "cocos2d.h"
#include "parts/Tier.h"
#include "../../Characters/Character.h"
#include"PartyContent.h"
#include"ui/CocosGUI.h"

USING_NS_CC;
class PartyLayer {
public:
	PartyContent* contents[5];
	LayerGradient* content;
	void makePartyBtn(Tier t, Character *);
	ui::ScrollView *scrollView;
	ui::Button *cancelBtn;
	PartyLayer();
};