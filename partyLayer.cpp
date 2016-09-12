#pragma once
#include "partyLayer.h"
#include "OHDialog.h"
#include"ui/CocosGUI.h"
#include"scene/RaidScene.h"
#include "partyContent.h"

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
	scrollView->setInnerContainerSize(Size(490, 1050));
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setPosition(Point(0,0));
	scrollView->setBackGroundImageScale9Enabled(true);
	scrollView->setBackGroundImage("popUpFrame.png");
	content->addChild(scrollView);
}

void PartyLayer::makePartyBtn(Tier t, Character *p) {
	for (int i = 0; i < 5; i++) {
		PartyContent *tempContent = new PartyContent(t,p);
		ui::Button*btn = tempContent->content;
		btn->setAnchorPoint(Point(0, 1));
		btn->setPosition(Point(10, 1030 - 200 * i));
		btn->setTag(i);
		btn->addTouchEventListener([tempContent](Ref*sender, ui::Button::TouchEventType e) {
			if (e == ui::Button::TouchEventType::ENDED) {
				std::string temp = tempContent->getStringContent();
				OHDialog dialog(Size(450, 300), "테스트", temp+"참여하시겠습니까?");
				ui::Button* btn = (ui::Button*)sender;
				dialog.okBtn->addTouchEventListener([tempContent](Ref*sender2, ui::Button::TouchEventType e) {
					Director::getInstance()->pushScene(Raid::createScene(tempContent->list));
				});
				dialog.addedTo(btn->getParent()->getParent()->getParent());
				
			}
		});
		scrollView->addChild(btn);
	}
}