/*
FileName:	RaidScene.cpp
Revision:	2016/08/23 by PorcaM
*/

#include "RaidScene.h"
#include "characters\Character.h"
#include "skillinstance\SkillFactory.h"

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
	Tier tempT = Tier(1);
	string tl[6] = { "MeleeNPC", "Monster", "TankNPC", "MeleeNPC", "MeleeNPC", "RangeNPC" };
	string rl[6] = { "melee.png", "monster.png", "tank.png", "melee.png", "melee.png", "range.png" };

	int borderline = visibleSize.height - 240;

	auto playerLayer = Layer::create();
	Sprite *player[5];
	for (int i = 0; i < 5; i++)
		player[i] = Sprite::create("plate2.png");
	Character *cl[6];
	for (int i = 0, j = 0; i < 6; i++) {
		if (i == 1) continue;
		cl[i] = Character::create(rl[i], tempT, tl[i], 5);
		cl[i]->setPosition(Vec2(0, 0));
		cl[i]->setScale(0.5f);
		cl[i]->setAnchorPoint(Vec2(0, 0));
		player[j++]->addChild(cl[i]);
	}
	for (int i = 0; i < 5; i++) {
		player[i]->setAnchorPoint(Vec2(0, 1));
		player[i]->setPosition(Vec2(0, -120 * i));

	}
	for (int i = 0; i < 5; i++)
		playerLayer->addChild(player[i]);
	playerLayer->setAnchorPoint(Vec2(0, 1));
	playerLayer->setPosition(0, borderline);
	this->addChild(playerLayer);

	auto bossLayer		= Layer::create();
	cl[1] = Character::create(rl[1], tempT, tl[1], 5);
	cl[1]->setPosition(Vec2(visibleSize.width / 2, 120));
	cl[1]->setScale(1.0f);
	cl[1]->setAnchorPoint(Vec2(0.5, 0.5));
	bossLayer->addChild(cl[1]);
	auto bossHP = Sprite::create("hp1.png");
	bossHP->setAnchorPoint(Vec2(0, 0.5));
	bossHP->setPosition(Vec2(0, 0));
	bossHP->setScale(1.0f);
	bossLayer->addChild(bossHP);
	auto RGBbg = Sprite::create("plate.png");
	auto RGBLog = Label::create("my message\n100\n100\n100", "fonts/arial", 20);
	RGBLog->setAnchorPoint(Vec2(0, 1));
	RGBLog->setPosition(Vec2(0, RGBbg->getContentSize().height));
	RGBbg->addChild(RGBLog);
	RGBbg->setPosition(Vec2(80, 120));
	bossLayer->addChild(RGBbg);
	bossLayer->setPosition(Vec2(0, borderline));
	this->addChild(bossLayer);

	auto skillLayer = Layer::create();
	Skill *sl[5];
	for (int i = 0; i < 5; i++) {
		sl[i] = SkillFactory::getSkill(heal);
		sl[i]->printInfo();
		sl[i]->initWithFile("images/skill2.png");
		sl[i]->setPosition(Vec2(0, -120 * i));
		sl[i]->setAnchorPoint(Vec2(1, 1));
		sl[i]->setScale(0.5f);
		skillLayer->addChild(sl[i]);
	}
	skillLayer->setAnchorPoint(Vec2(1, 1));
	skillLayer->setPosition(Vec2(visibleSize.width, borderline));
	this->addChild(skillLayer);

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