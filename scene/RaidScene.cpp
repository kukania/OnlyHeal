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

int Raid::selectedNum = -1;
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
	this->setName("Background");
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Raid::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Raid::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Raid::onTouchEnded, this);
	//Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	setBackground(Color4F(1, 1, 1, 1));
	Tier tempT = Tier(1);
	this->makeSkillScrollView();
	return true;
}

void Raid::makeSkillScrollView() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	this->scv = ui::ScrollView::create();
	scv->setContentSize(Size(130,580));
	scv->setInnerContainerSize(Size(120, 80 * SKILLNUM + 20));
	scv->setBackGroundImageScale9Enabled(true);
	scv->setBackGroundImage("images/raid/outline.png");
	scv->setDirection(ui::ScrollView::Direction::VERTICAL);
	scv->setBounceEnabled(true);
	scv->setTouchEnabled(true);
	scv->setPosition(Point(400, 30));
	scv->setSwallowTouches(false);
	scv->setName("scv");
	HealSkillFactory hsf;
	hsf.initAllSkills();
	Skill** sl = hsf.getSkillsList(SKILLNUM);
	SkillFrame *sf[SKILLNUM];
	int borderline = visibleSize.height - 240;
	for (int i = 0; i < SKILLNUM; i++) {
		sf[i] = new SkillFrame(sl[i]);
		sf[i]->_button->setContentSize(Size(100, 80));
		sf[i]->_button->setAnchorPoint(Vec2(0,1));
		sf[i]->_button->setPosition(Vec2(10, 80* SKILLNUM +i*-80));
		sf[i]->_button->setTag(i);
		this->skillBtnPosition[i] = sf[i]->_button->getPosition();
		scv->addChild(sf[i]->_button);
	}
	this->addChild(scv);
}
bool Raid::onTouchBegan(Touch* touch, Event*) {
	Point location = touch->getLocation();
	if (selectedNum != -1) {
		ui::Button * btn = (ui::Button *)scv->getChildByTag(selectedNum);
		btn->retain();
		btn->removeFromParent();
		this->addChild(btn);
		btn->setAnchorPoint(Point(0.5, 0.5));
		btn->setPosition(location);
		selectedBtn = btn;
		btn->release();
	}
	return true;
}
void Raid::onTouchMoved(Touch *touch, Event*) {
	Point location = touch->getLocation();
	if (selectedBtn !=NULL) {
		selectedBtn->setPosition(location);
	}
}
void Raid::onTouchEnded(Touch *touch, Event*) {
	if (selectedBtn != NULL) {
		selectedBtn->retain();
		selectedBtn->removeFromParent();
		selectedBtn->setAnchorPoint(Point(0, 1));
		selectedBtn->setPosition(skillBtnPosition[selectedBtn->getTag()]);
		scv->addChild(selectedBtn);
		selectedBtn->release();
		selectedBtn = NULL;
	}
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

	bf = new BossFrame(cl[0]);
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