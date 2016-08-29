#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "skillinstance\SkillFactory.h"
#include "statusHexa.h"

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
	makeBackGround();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved= CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded= CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
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

	this->statusHexa = DrawNode::create();
	StatusHexa temp(175);
	statusHexa->drawPolygon(temp.corners, 6, Color4F(1.0f, 0.3f, 0.3f, 1), 0, Color4F(1.0f, 0.3f, 0.3f, 1));
	/*
		temp.setStatusVertex(character);
		statusHexa->addChild()
	*/
	backGround->addChild(this->statusHexa);
	this->statusHexa->setPosition(270, 750);

	characterGroup = Layer::create();
	characterGroup->setColor(Color3B(255, 255, 255));
	characterGroup->setContentSize(Size(540, 200));
	backGround->addChild(characterGroup);
	characterGroup->setPosition(0, 375);

	auto firstChar = Sprite::create("temp.png");
	characterGroup->addChild(firstChar);
	firstChar->setAnchorPoint(Vec2(0.0f, 0.5f));
	firstChar->setPosition(20, 100);
	firstChar->setScaleY(0.7f);
	firstChar->setTag(0);

	auto secondChar = Sprite::create("temp.png");
	characterGroup->addChild(secondChar);
	secondChar->setPosition(270, 100);
	secondChar->setScaleY(0.7f);
	secondChar->setTag(1);

	auto thirdChar = Sprite::create("temp.png");
	characterGroup->addChild(thirdChar);
	thirdChar->setAnchorPoint(Vec2(1.0f, 0.5f));
	thirdChar->setPosition(520, 100);
	thirdChar->setScaleY(0.7f);
	thirdChar->setTag(2);
	/*scroll view test -start-*/
	scrollView = ui::ScrollView::create();
	scrollView->setContentSize(Size(500, 110));
	scrollView->setInnerContainerSize(Size(1080, 110));
	scrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	scrollView->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
	scrollView->setBackGroundColor(Color3B(255, 0, 0));
	scrollView->setBounceEnabled(true);
	scrollView->setTouchEnabled(true);
	scrollView->setSwallowTouches(true);
	scrollView->setPosition(Point(20, 375));
	backGround->addChild(scrollView);
	scrollView->setVisible(false);
	
	/*scroll view test -end-*/
	auto menuBtn = ui::Button::create("temp.png", "temp.png", "temp.png");
	menuBtn->setPosition(Vec2(270, 100));
	menuBtn->setTouchEnabled(true);
	menuBtn->setSwallowTouches(false);
	menuBtn->setTitleText("hello");
	menuBtn->setTitleFontSize(20);
	menuBtn->setScale9Enabled(true);
	menuBtn->setContentSize(Size(100, 100));
	backGround->addChild(menuBtn);
	menuBtn->setName("menuBtn");
	positionArr[MENUBTN] = menuBtn->getPosition();

	auto partyLabel = Label::createWithSystemFont("party go","",30,Size(300,100), TextHAlignment::CENTER, TextVAlignment::CENTER);
	partyLabel->setPosition(Vec2(270, 200));
	partyLabel->setColor(Color3B::BLACK);
	partyLabel->setVisible(false);
	partyLabel->setName("partyBtn");
	backGround->addChild(partyLabel);

	auto skillTree = Label::createWithSystemFont("skillTree go", "", 30, Size(300, 100), TextHAlignment::CENTER, TextVAlignment::CENTER);
	skillTree->setPosition(Vec2(270, 300));
	skillTree->setColor(Color3B::BLACK);
	skillTree->setVisible(false);
	skillTree->setName("skillTreeBtn");
	backGround->addChild(skillTree);
}
bool HelloWorld::onTouchBegan(Touch * t, Event *e) {
	Point location = t->getLocation();
	CCLOG("location x:%f, y:%f", location.x, location.y);
	if (this->checkCharacterGroup(location))
		return true;
	auto btn=(ui::Button*)backGround->getChildByName("menuBtn");
	auto rect = btn->getBoundingBox();
	if (rect.containsPoint(location)) {
		((Label*)backGround->getChildByName("skillTreeBtn"))->setVisible(true);
		((Label*)backGround->getChildByName("partyBtn"))->setVisible(true);
		this->menuBtnTouched = true;
	}
	return true;
}
void HelloWorld::onTouchMoved(Touch *t, Event *e) {
	if (this->menuBtnTouched) {
		Point p = t->getLocation();
		auto btn = ((ui::Button*)backGround->getChildByName("menuBtn"));
		btn->setPosition(p);
	}
}
void HelloWorld::onTouchEnded(Touch *t, Event *e) {
	if (this->menuBtnTouched) {
		auto sB=(Label*)backGround->getChildByName("skillTreeBtn");
		auto pB=(Label*)backGround->getChildByName("partyBtn");
		if (sB->getBoundingBox().containsPoint(t->getLocation())) {
		
		}
		else if (pB->getBoundingBox().containsPoint(t->getLocation())) {
		
		}
		sB->setVisible(false);
		pB->setVisible(false);
	}
	this->menuBtnTouched = false;
	((ui::Button*)backGround->getChildByName("menuBtn"))->setPosition(positionArr[MENUBTN]);
}
bool HelloWorld::checkCharacterGroup(Point location) {
	static int touchNum = -1;
	location.x -= characterGroup->getPosition().x;
	location.y -= characterGroup->getPosition().y;
	bool flag = false;
	for (int i = 0; i < 3; i++) {
		auto spr = characterGroup->getChildByTag(i);
		Rect rect = spr->getBoundingBox();
		if (rect.containsPoint(location)) {
			if (touchNum == -1) {
				flag = true;
				auto action = MoveBy::create(0.1, Point(0, 100));
				characterGroup->runAction(action);
				auto action2 = ScaleBy::create(0.1, 0.625f);
				auto action3 = MoveBy::create(0.1, Point(0, 50));
				for (int i = 0; i < 5; i < i++) {
					auto btn = ui::Button::create();
					btn->loadTextures("temp.png", "temp.png", "temp.png");
					btn->setTouchEnabled(true);
					btn->setAnchorPoint(Vec2(0, 0));
					btn->setPosition(Vec2(10 + i * 100, 10));
					btn->setScale9Enabled(true);
					btn->setContentSize(Size(90, 90));
					btn->setTag(i);
					btn->addTouchEventListener([](Ref* sender, ui::Button::TouchEventType e) {
						if (e == ui::Button::TouchEventType::BEGAN) {
							int a = ((ui::Button*)sender)->getTag();
							CCLOG("hello tag:%d",a);
						}
					});
					this->scrollView->addChild(btn);
				}
				auto callFunc = CallFunc::create([&]() {
					this->scrollView->setVisible(true);
				});
				auto seq = Sequence::create(action2, action3, callFunc,NULL);
				statusHexa->runAction(seq);
				touchNum = i;
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
		touchNum = -1;
		auto action = MoveBy::create(0.1, Point(0, -100));
		characterGroup->runAction(action);
		auto action2 = ScaleBy::create(0.1, 1.6f);
		auto action3 = MoveBy::create(0.1, Point(0, -50));
		auto callFunc = CallFunc::create([&]() {
			this->scrollView->setVisible(false);
		});
		auto seq = Sequence::create(callFunc,action3, action2, NULL);
		statusHexa->runAction(seq);
	}
	return false;
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
