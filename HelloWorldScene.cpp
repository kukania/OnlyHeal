#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "skillinstance\Factory\SkillFactory.h"
#include "partyLayer.h"
#include "ConvertKorean.h"
#include "OHDialog.h"

#include<iostream>
using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!Layer::init()) {
		return false;
	}
	positionArr.assign(10, Vec2(0, 0));
	p = new Player();
	scrollViewShow = false;
	menuBtnTouched = false;

	makeBackGround();
	makePlayerWithItem();
	drawPlayerStatusHexa();
	this->touchNum = -1;
	
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}
void HelloWorld::makeBackGround() {
	backGround = DrawNode::create();
	Vec2 corners[4] = {
		Vec2(0,960),
		Vec2(540,960),
		Vec2(540,0),
		Vec2(0,0)
	};
	backGround->drawPolygon(corners, 4, Color4F(1.0f, 1.0f, 1.0f, 1), 0, Color4F(1.0f, 0.3f, 0.3f, 1));
	this->addChild(backGround);


	this->statusLayer = LayerColor::create(Color4B(0,255,0,255));
	statusLayer->setContentSize(Size(540, 300));
	statusLayer->setPosition(Point(0,600));
	backGround->addChild(statusLayer);

	for (int i = 0; i < 4; i++) {
		showPlayerStatus[i] = Label::createWithTTF("Tier", "fonts/sdCrayon.ttf", 28, Size(100, 50));
		showPlayerStatus[i]->setColor(Color3B(0, 0, 0));
		showPlayerStatus[i]->setPosition(Point(400, 250 - i * 50));
		statusLayer->addChild(showPlayerStatus[i]);
	}

	this->statusHexa = DrawNode::create();
	this->statusHexaContent=StatusHexa(130);
	statusHexa->drawPolygon(statusHexaContent.corners, 6, Color4F(1.0f, 0.3f, 0.3f, 1), 0, Color4F(1.0f, 0.3f, 0.3f, 1));
	this->statusHexa->setPosition(150, 150);
	statusLayer->addChild(this->statusHexa);

	characterGroup = Layer::create();
	characterGroup->setColor(Color3B(255, 255, 255));
	characterGroup->setContentSize(Size(540, 200));
	backGround->addChild(characterGroup);
	characterGroup->setPosition(0, 375);

	auto firstChar = Sprite::create("char.png");
	characterGroup->addChild(firstChar);
	firstChar->setAnchorPoint(Vec2(0.0f, 0.5f));
	firstChar->setScale(1.6f);
	firstChar->setPosition(20, 100);
	firstChar->setTag(0);
	positionArr[CHA] = firstChar->getPosition();

	auto secondChar = Sprite::create("rac.png");
	characterGroup->addChild(secondChar);
	secondChar->setPosition(270, 100);
	secondChar->setScale(1.6f);
	secondChar->setTag(1);
	positionArr[RAC] = secondChar->getPosition();

	auto thirdChar = Sprite::create("ter.png");
	characterGroup->addChild(thirdChar);
	thirdChar->setAnchorPoint(Vec2(1.0f, 0.5f));
	thirdChar->setPosition(520, 100);
	thirdChar->setScale(1.6f);
	thirdChar->setTag(2);
	positionArr[TER] = thirdChar->getPosition();

	/*scroll view test -start-*/
	scrollView = ui::ScrollView::create();
	scrollView->setContentSize(Size(500, 110));
	scrollView->setInnerContainerSize(Size(1080, 110));
	scrollView->setBackGroundImageScale9Enabled(true);
	scrollView->setBackGroundImage("rect.png");
	scrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	scrollView->setBounceEnabled(true);
	scrollView->setTouchEnabled(true);
	scrollView->setSwallowTouches(false);
	scrollView->setPosition(Point(20, 375));
	backGround->addChild(scrollView);
	scrollView->setVisible(false);
	positionArr[SCROLLVIEW] = scrollView->getPosition();
	scrollView->setName("scrollView");
	/*scroll view test -end-*/

	auto partyLabel = Label::createWithTTF("party go", "fonts/sdCrayon.ttf", 30, Size(300, 100), TextHAlignment::CENTER, TextVAlignment::CENTER);
	partyLabel->setPosition(Vec2(270, 200));
	partyLabel->setColor(Color3B::BLACK);
	partyLabel->setVisible(false);
	partyLabel->setName("partyBtn");
	backGround->addChild(partyLabel);

	auto skillTree = Label::createWithTTF("skillTree go", "fonts/sdCrayon.ttf", 30, Size(300, 100), TextHAlignment::CENTER, TextVAlignment::CENTER);
	skillTree->setPosition(Vec2(270, 300));
	skillTree->setColor(Color3B::BLACK);
	skillTree->setVisible(false);
	skillTree->setName("skillTreeBtn");
	backGround->addChild(skillTree);

	auto menuBtn = ui::Button::create("menu.png", "menu.png", "");
	menuBtn->setPosition(Vec2(270, 100));
	menuBtn->setTouchEnabled(true);
	menuBtn->setSwallowTouches(false);
	menuBtn->setTitleFontSize(20);
	menuBtn->setScale9Enabled(true);
	menuBtn->setContentSize(Size(100, 100));
	backGround->addChild(menuBtn);
	menuBtn->setName("menuBtn");
	positionArr[MENUBTN] = menuBtn->getPosition();

}
void HelloWorld::makePlayerWithItem() {
	Tier *t;
	for (int i = WEAPON; i <=ARTIFACT; i++) {
		for (int j = 0; j < 5; j++) {
			t = new Tier((rand() % 81));
			Item *w=new Item(*t,i,MyRGB::getMyRGBRandom());
			//p->inventory[i].pushItemList(*w);
		}
		//p->equipSelectedItem(0,i);
	}
}
void HelloWorld::drawPlayerStatusHexa() {

	DrawNode* t = (DrawNode*)statusHexa->getChildByName("playerStatus");
	if (t != NULL) {
		t->removeFromParent();
	}

	statusHexaContent.setStatusVertex(p);
	this->playerStatusHexa = DrawNode::create();
	playerStatusHexa->drawPolygon(statusHexaContent.statusVertex, 6, Color4F(0.0f, 0.3f, 0.3f, 1), 0, Color4F(0.0f, 0.3f, 0.3f, 1));
	playerStatusHexa->setName("playerStatus");
	statusHexa->addChild(this->playerStatusHexa);
}
bool HelloWorld::onTouchBegan(Touch * t, Event *e) {
	Point location = t->getLocation();
	auto btn = (ui::Button*)backGround->getChildByName("menuBtn");
	auto rect = btn->getBoundingBox();
	if (rect.containsPoint(location)) {
		((Label*)backGround->getChildByName("skillTreeBtn"))->setVisible(true);
		((Label*)backGround->getChildByName("partyBtn"))->setVisible(true);
		this->menuBtnTouched = true;
	}
	return true;
}
void HelloWorld::onTouchMoved(Touch *t, Event *e) {
	Point p = t->getLocation();
	if (this->menuBtnTouched) {
		auto btn = ((ui::Button*)backGround->getChildByName("menuBtn"));
		btn->setPosition(p);
	}
}
void HelloWorld::onTouchEnded(Touch *t, Event *e) {
	Point location = t->getLocation();
	auto scV = (ui::ScrollView*)backGround->getChildByName("scrollView");
	if (scrollViewShow&&scV->getBoundingBox().containsPoint(location))
		return;

	if (this->checkCharacterGroup(location))
		return;

	if (this->menuBtnTouched) {
		auto sB = (Label*)backGround->getChildByName("skillTreeBtn");
		auto pB = (Label*)backGround->getChildByName("partyBtn");
		if (sB->getBoundingBox().containsPoint(t->getLocation())) {
			//skillTreeLayer
		}
		else if (pB->getBoundingBox().containsPoint(t->getLocation())) {
			//partyLayer
			/*
				make party list
			*/
			PartyLayer partyLayer;
			partyLayer.makePartyBtn(p->getStatus()->evalTier());
			this->backGround->addChild(partyLayer.content);
		}
		sB->setVisible(false);
		pB->setVisible(false);
	}
	this->menuBtnTouched = false;
	((ui::Button*)backGround->getChildByName("menuBtn"))->setPosition(positionArr[MENUBTN]);
}
bool HelloWorld::checkCharacterGroup(Point location) {
	location.x -= characterGroup->getPosition().x;
	location.y -= characterGroup->getPosition().y;
	bool flag = false; //flag for scrollview not visible
	for (int i = 0; i < 3; i++) {
		auto spr = characterGroup->getChildByTag(i);
		Rect rect = spr->getBoundingBox();
		if (rect.containsPoint(location)) {
			if (touchNum != i) {
				scrollViewSetting(i);
			}
			if (touchNum == -1 ) {
				scrollViewShow = true;
				flag = true;
				touchNum = i;
				auto action = MoveBy::create(0.1, Point(0, 100));
				characterGroup->runAction(action);
				auto action2 = ScaleBy::create(0.1, 0.625f);
				auto action3 = MoveBy::create(0.1, Point(-50,30));
				auto callFunc = CallFunc::create([&]() {
					this->scrollView->setVisible(true);
				});
				auto seq = Sequence::create(action2, action3,callFunc, NULL);
				statusLayer->runAction(seq);
				break;
			}
			else {
				flag = true;
				touchNum = i;
			}
			return true;
		}
	}
	if (!flag && touchNum != -1) {
		scrollViewShow = false;
		touchNum = -1;
		auto action = MoveBy::create(0.1, Point(0, -100));
		characterGroup->runAction(action);
		auto action2 = ScaleBy::create(0.1, 1.6f);
		auto action3 = MoveBy::create(0.1, Point(50,-30));
		auto callFunc = CallFunc::create([&]() {
			this->scrollView->setVisible(false);
		});
		auto seq = Sequence::create(callFunc, action3,action2, NULL);
		statusLayer->runAction(seq);
	}
	return false;
}
void HelloWorld::scrollViewSetting(int i) {
	//scrollVIew setting
	/*ScrollView Type set, content size*/
	Size temp = scrollView->getInnerContainerSize();
	temp.width = p->inventory[i].itemList.size() * 100 + 40;
	scrollView->setInnerContainerSize(temp);
	scrollView->removeAllChildren();
	/*add items*/
	for (int j = 0; j < p->inventory[i].itemList.size(); j++) {
		Item &tempItem = p->inventory[i].itemList[j];
		string str = tempItem.toString();
		auto btn = ui::Button::create();
		btn->loadTextures("box.png", "box.png", "box.png");
		btn->setTouchEnabled(true);
		btn->setSwallowTouches(false);
		btn->setAnchorPoint(Vec2(0, 0));
		btn->setPosition(Vec2(20 + j * 100, 15));
		btn->setScale9Enabled(true);
		btn->setContentSize(Size(80, 80));
		btn->setTag(j);
		btn->addTouchEventListener([i,this, str](Ref* sender, ui::Button::TouchEventType e) {
			if (e == ui::Button::TouchEventType::ENDED) {
				int a = ((ui::Button*)sender)->getTag();
				OHDialog dialog(Size(400, 250), "테스트", str + "장착하시겠습니까?");
				dialog.okBtn->addTouchEventListener([i,this, a](Ref *sender, ui::Button::TouchEventType e) {
					if (e == ui::Button::TouchEventType::ENDED) {
						int deb;
						this->p->equipSelectedItem(a, this->touchNum);
						this->drawPlayerStatusHexa();
						this->scrollViewSetting(i);
						ui::Button *t = (ui::Button*)sender;
						t->getParent()->removeFromParent();
					}
				});
				dialog.addedTo(this->backGround);
			}
		});

		auto txt = Label::createWithTTF(_AtoU8(tempItem.getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
		txt->setPosition(Point(40, 40));
		btn->addChild(txt);
		if (&tempItem == p->inventory[i].equiped) {
			auto equipedLabel = Label::createWithTTF(_AtoU8("장착중"), "fonts/sdCrayon.ttf", 24);
			Size eqlSize = equipedLabel->getContentSize();
			auto labelLayer = LayerColor::create(Color4B(255, 0, 255, 255), eqlSize.width, eqlSize.height);
			equipedLabel->setAnchorPoint(Point(0, 0));
			equipedLabel->setPosition(Point(0, 0));
			labelLayer->addChild(equipedLabel);
			labelLayer->setPosition(Point(8, 25));
			btn->addChild(labelLayer);
		}
		this->scrollView->addChild(btn);
	}
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
