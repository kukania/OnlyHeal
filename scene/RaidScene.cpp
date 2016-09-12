/*
FileName:	RaidScene.cpp
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/30 by PorcaM
*/

#include "RaidScene.h"
#include "ui/CocosGUI.h"
#include "RaidComponent\UnitFrame.h"
#include "RaidComponent\BossFrame.h"
#include "RaidComponent\SkillFrame.h"
#include "characters\Character.h"
#include "skillinstance\Factory\HealSkillFactory.h"
#include <cstdio>

USING_NS_CC;

Scene* Raid::createScene()
{
	auto scene = Scene::create();
	auto layer = Raid::create();
	scene->addChild(layer);
	return scene;
}
Scene* Raid::createScene(Character **a) {
	auto scene = Scene::create();
	auto layer = Raid::create();
	layer->cl = a;
	layer->makeUnitFrame();
	scene->addChild(layer);
	return scene;
}
bool Raid::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Raid::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// PorcaM
	setBackground(Color4F(1, 1, 1, 1));

	Tier tempT = Tier(1);
	auto SkillGrid = CCNode::create();
	const int skillnum = 5;
	HealSkillFactory hsf;
	hsf.initAllSkills();
	Skill** sl = hsf.getSkillsList(skillnum);
	SkillFrame *sf[skillnum];
	int borderline = visibleSize.height - 240;
	for (int i = 0; i < skillnum; i++) {
		sf[i] = new SkillFrame(sl[i]);
		sf[i]->setAnchorPoint(Vec2(1, 0));
		sf[i]->setPosition(Vec2(0, i*-60));
		SkillGrid->addChild(sf[i]);
	}
	SkillGrid->setScale(1.6f);
	SkillGrid->setAnchorPoint(Vec2(0, 0));
	SkillGrid->setPosition(Vec2(visibleSize.width-80, borderline-140));
	this->addChild(SkillGrid, 10);
	return true;
}
void Raid::makeUnitFrame() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	int borderline = visibleSize.height - 240;
	auto UnitGrid = CCLayerColor::create();
	UnitFrame *uf[4];
	for (int i = 2; i <=5; i++) {
		uf[i-2] = new UnitFrame(cl[i]);
		uf[i-2]->setPosition(Vec2(0, (i-2)*-90));
		UnitGrid->addChild(uf[i-2]);
	}
	UnitGrid->setScale(1.6f);
	UnitGrid->setAnchorPoint(Vec2(0, 0));
	UnitGrid->setPosition(Vec2(0, borderline - 180));
	this->addChild(UnitGrid);

	BossFrame *bf = new BossFrame(cl[0]);
	bf->setScale(1.6f);
	bf->setPosition(Vec2(visibleSize.width / 2, borderline + 80));
	this->addChild(bf);
}
void Raid::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif 
}

void Raid::setBackground(Color4F color) {
	auto visibleSize	= Director::getInstance()->getVisibleSize();
	auto backGround		= DrawNode::create();
	//CCLOG("width:%f height:%f visibleSize", visibleSize.width, visibleSize.height);
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

void Raid::initUnitGrid() {
	return;
}
void Raid::initBossFrame(Character *character) {
	return;
}
void Raid::initSkillGrid() {
	return;
}