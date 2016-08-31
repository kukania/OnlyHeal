/*
FileName:	RaidScene.cpp
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/30 by PorcaM
*/

#include "RaidScene.h"
#include "characters\Character.h"
#include "skillinstance\SkillFactory.h"
#include "RaidComponent\UnitFrame.h"
#include "RaidComponent\BossFrame.h"
#include "RaidComponent\SkillFrame.h"
#include "ui/CocosGUI.h"
#include <cstdio>

USING_NS_CC;

Scene* Raid::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Raid::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Raid::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Raid::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below
	setBackground(Color4F(1, 1, 1, 1));

	Tier tempT = Tier(1);
	string tl[6] = { "Monster", "MeleeNPC", "TankNPC", "MeleeNPC", "MeleeNPC", "RangeNPC" };
	Character *cl[6];
	for (int i = 0; i < 6; i++) {
		cl[i] = Character::create(tempT, tl[i], 5);
	}
	int borderline = visibleSize.height - 240;

	auto UnitGrid = CCLayerColor::create();
	//UnitGrid->initWithColor(Color4B(0, 0, 0, 255));
	UnitFrame *uf[5];
	for (int i = 0; i < 5; i++) {
		uf[i] = new UnitFrame(cl[i + 1]);
		uf[i]->setPosition(Vec2(0, i*-90));
		UnitGrid->addChild(uf[i]);
	}
	UnitGrid->setAnchorPoint(Vec2(0, 1));
	UnitGrid->setPosition(Vec2(0, borderline));
	UnitGrid->setScale(1.6f);
	this->addChild(UnitGrid);

	BossFrame *bf = new BossFrame(cl[0]);
	bf->setScale(1.6f);
	bf->setPosition(Vec2(visibleSize.width/2, borderline+80));
	this->addChild(bf);

	/*auto skillLayer = Layer::create();
	Skill *sl[5];
	for (int i = 0; i < 5; i++) {
		sl[i] = SkillFactory::getSkill(heal);
		sl[i]->initWithFile("images/skill2.png");
		sl[i]->setPosition(Vec2(0, -120 * i));
		sl[i]->setAnchorPoint(Vec2(1, 1));
		sl[i]->setScale(0.5f);
		skillLayer->addChild(sl[i]);
	}
	skillLayer->setAnchorPoint(Vec2(1, 1));
	skillLayer->setPosition(Vec2(visibleSize.width, borderline));
	this->addChild(skillLayer);*/

	auto SkillGrid = Layer::create();
	const int skillnum = 5;
	Skill *sl[skillnum];
	SkillFrame *sf[skillnum];
	for (int i = 0; i < skillnum; i++) {
		sl[i] = SkillFactory::getSkill(heal);
		sf[i] = new SkillFrame(sl[i]);
		sf[i]->setPosition(Vec2(0, i*-100));
		SkillGrid->addChild(sf[i]);
	}
	SkillGrid->setPosition(Vec2(500, borderline));
	this->addChild(SkillGrid);

	return true;
}
void Raid::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);   
}

/*
Custom class functions
Help for generating instances.
2016/08/24 by PorcaM
*/
void Raid::setBackground(Color4F color) {
	auto visibleSize	= Director::getInstance()->getVisibleSize();
	auto backGround		= DrawNode::create();
	Vec2 corners[4]		= {
		Vec2(0, visibleSize.height),
		Vec2(visibleSize.width, visibleSize.height),
		Vec2(visibleSize.width, 0),
		Vec2(0, 0)
	};
	backGround->drawPolygon(corners, 4, color, 0, color);
	this->addChild(backGround);
	return;
}