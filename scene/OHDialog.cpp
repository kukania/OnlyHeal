#pragma once
#include"cocos2d.h"
#include"OHDialog.h"
#include "ConvertKorean.h"
USING_NS_CC;
OHDialog::OHDialog(Size layerSize,std::string title, std::string content) {
	dialogContent = ui::Scale9Sprite::create("images/dialog/dialog.png");
	dialogContent->setContentSize(layerSize);
	
	auto dialogTitle = Label::createWithTTF(_AtoU8(title.c_str()), "fonts/sdCrayon.ttf",35);
	dialogTitle->setColor(Color3B(0, 0, 0));
	dialogTitle->setPosition(Point(10, layerSize.height- 10));
	dialogTitle->setAnchorPoint(Point(0, 1));
	dialogContent->addChild(dialogTitle);

	auto dcontent = Label::createWithTTF(_AtoU8(content.c_str()), "fonts/sdCrayon.ttf", 25);
	dcontent->setColor(Color3B(0, 0, 0));
	dcontent->setPosition(Point(10, layerSize.height-40));
	dcontent->setAnchorPoint(Point(0, 1));
	dialogContent->addChild(dcontent);

	okBtn = ui::Button::create("images/dialog/buttonu.png","images/dialog/buttond.png","");
	okBtn->setScale9Enabled(true);
	okBtn->setContentSize(Size(layerSize.width / 5, layerSize.height / 4));
	okBtn->setAnchorPoint(Point(1, 0));
	okBtn->setPosition(Point(layerSize.width - 10, 10));
	auto okLabel = Label::createWithTTF(_AtoU8("확인"), "fonts/sdCrayon.ttf", 35);
	okLabel->setColor(Color3B(0, 0, 0));
	okLabel->setPosition(Point(layerSize.width / 10, layerSize.height / 8));
	okBtn->addChild(okLabel);
	dialogContent->addChild(okBtn);

	cancelBtn = ui::Button::create("images/dialog/buttonu.png", "images/dialog/buttond.png", "");
	cancelBtn->setScale9Enabled(true);
	cancelBtn->setContentSize(Size(layerSize.width / 5, layerSize.height / 4));
	cancelBtn->setAnchorPoint(Point(1, 0));
	cancelBtn->setPosition(Point(layerSize.width * 3 / 4 - 10, 10));
	auto cancelLabel = Label::createWithTTF(_AtoU8("취소"), "fonts/sdCrayon.ttf", 35);
	cancelLabel->setColor(Color3B(0, 0, 0));
	cancelLabel->setPosition(Point(layerSize.width / 10, layerSize.height / 8));
	cancelBtn->addChild(cancelLabel);
	dialogContent->addChild(cancelBtn);
	cancelBtn->addTouchEventListener([](Ref *sender,ui::Button::TouchEventType e) {
		if (e == ui::Button::TouchEventType::ENDED) {
			ui::Button *btn = (ui::Button*)sender;
			btn->getParent()->removeFromParentAndCleanup(true);
		}
	});
}
void OHDialog::addedTo(Node* a) {
	dialogContent->setPosition(Vec2(270, 490));
	dialogContent->setName("Dialog");
	Node *p = a->getChildByName("Dialog");
	if (p != NULL) p->removeFromParent();
	a->addChild(dialogContent);
}