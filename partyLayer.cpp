#pragma once
#include "partyLayer.h"
#include"ui/CocosGUI.h"

PartyLayer::PartyLayer() {
	content = LayerGradient::create(Color4B(255, 255, 255, 255), Color4B(255, 255, 255, 255));
	content->setPosition(Vec2(25, 40));
	content->setContentSize(Size(490, 900));
	
	auto spr = ui::Scale9Sprite::create("partyFrame.png");
	spr->setAnchorPoint(Point(0, 1));
	spr->setPosition(Point(0, 900));
	spr->setContentSize(Size(490, 60));
	content->addChild(spr);
	
	cancelBtn = ui::Button::create("partyOutBtn.png", "partyOutBtn.png", "partyOutBtn.png");
	cancelBtn->setAnchorPoint(Point(1, 1));
	cancelBtn->setPosition(Point(480, 50));
	cancelBtn->setScale9Enabled(true);
	cancelBtn->setContentSize(Size(50, 40));
	cancelBtn->addTouchEventListener([&](Ref*sender, ui::Button::TouchEventType e) {
		switch (e) {
		case ui::Button::TouchEventType::BEGAN:
			((Sprite*)((ui::Button*)sender)->getParent())->getParent()->removeFromParent();
			break;
		}
	});
	spr->addChild(cancelBtn);
	
	this->scrollView = ui::ScrollView::create();
	scrollView->setContentSize(Size(490, 840));
	scrollView->setSwallowTouches(false);
	scrollView->setInnerContainerSize(Size(490, 1800));
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setPosition(Point(0,0));
	scrollView->setBackGroundImageScale9Enabled(true);
	scrollView->setBackGroundImage("popUpFrame.png");
	for (int i = 0; i < 5; i++) {
		auto btn = ui::Button::create("partyFrame.png", "partyFrame.png", "partyFrame.png");
		btn->setScale9Enabled(true);
		btn->setContentSize(Size(470, 300));
		btn->setAnchorPoint(Point(0, 1));
		btn->setPosition(Point(10, 1790-300*i));
		btn->addTouchEventListener([](Ref*sender, ui::Button::TouchEventType e) {
			if (e == ui::Button::TouchEventType::ENDED) {
				
			}
		});
		scrollView->addChild(btn);
	}
	content->addChild(scrollView);
}