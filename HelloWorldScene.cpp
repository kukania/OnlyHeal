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
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	makeBackGround();
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

	auto menuBtn = Sprite::create("temp.png");
	backGround->addChild(menuBtn);
	menuBtn->setPosition(270, 100);
	menuBtn->setTag(0);
}
bool HelloWorld::onTouchBegan(Touch * t, Event *e) {
	Point location = t->getLocation();
	if (this->checkCharacterGroup(location))
		return true;
	return true;
}
bool HelloWorld::checkCharacterGroup(Point location) {
	static int touchNum=-1;
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
				statusHexa->runAction(action2);
				statusHexa->runAction(action3);
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
	if (!flag && touchNum!=-1) {
		touchNum = -1;
		auto action = MoveBy::create(0.1, Point(0, -100));
		characterGroup->runAction(action);
		auto action2 = ScaleBy::create(0.1,1.6f);
		auto action3 = MoveBy::create(0.1, Point(0, -50));
		statusHexa->runAction(action2);
		statusHexa->runAction(action3);
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
