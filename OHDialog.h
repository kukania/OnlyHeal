#pragma once
#include "cocos2d.h"
#include"ui/CocosGUI.h"
#include<string>
USING_NS_CC;
class OHDialog {
public:
	ui::Scale9Sprite *dialogContent;
	ui::Button *okBtn;
	ui::Button *cancelBtn;
	OHDialog(Size,std::string title,std::string content);
	void addedTo(Node* a);
};