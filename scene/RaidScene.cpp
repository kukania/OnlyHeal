/*
FileName:	RaidScene.cpp
Revision:	2016/08/23 by PorcaM
Modified:	2016/08/30 by PorcaM
*/

#include "RaidScene.h"
#include "ui/CocosGUI.h"
#include "RaidComponent/BossFrame.h"
#include "RaidComponent\SkillFrame.h"
#include "characters\Character.h"
#include "skillinstance\Factory\HealSkillFactory.h"
#include "OHDialog.h"
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
	
	this->makeSkillScrollView();
	//this->schedule(schedule_selector)
	this->schedule(schedule_selector(Raid::frameUpdate), 0.05);
	this->schedule(schedule_selector(Raid::moveBossFrame),0.5);
	this->schedule(schedule_selector(Raid::playingFunc), 0.5);
	this->schedule(schedule_selector(Raid::skillCoolDown), 0.5);
	this->schedule(schedule_selector(Raid::checkGameOver), 0.5);
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
}
bool Raid::onTouchBegan(Touch* touch, Event*) {
	Point location = touch->getLocation();
	if (selectedNum != -1) {
		ui::Button * btn = (ui::Button *)scv->getChildByTag(selectedNum);
		btn->retain();
		btn->removeFromParentAndCleanup(true);
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
		for (int i = 0; i < 4; i++) {
			Rect a;
			a.setRect(uf[i]->getPosition().x, uf[i]->getPosition().y, uf[i]->_background->getContentSize().width*1.6f, uf[i]->_background->getContentSize().height*1.6f);
			Point endPoint = touch->getLocation();
			if (a.containsPoint(endPoint)) {
				CCLOG("intersect");
				int num = selectedBtn->getTag();
				if(!cl[1]->mySkillSet[num]->isMulti())
					cl[1]->mySkillSet[num]->activate(cl, *cl[1], i+2);
				else
					cl[1]->mySkillSet[num]->activate(cl, *cl[1]);
				SkillInfo tempSkillInfo;
				tempSkillInfo.cl = cl[1];
				tempSkillInfo.skillNum = num;
				skillStorage.push_back(tempSkillInfo);
			}
		}
		selectedBtn->retain();
		selectedBtn->removeFromParentAndCleanup(true);
		selectedBtn->setAnchorPoint(Point(0, 1));
		selectedBtn->setPosition(skillBtnPosition[selectedBtn->getTag()]);
		scv->addChild(selectedBtn);
		selectedBtn->release();
		selectedBtn = NULL;
	}
}

void Raid::makeUnitFrame() {
	for (int i = 0; i < 6; i++) {
//		cl[i]->setCharacterList(cl);
		cl[i]->_timer = 0.0;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	int borderline = visibleSize.height - 240;
	
	for (int i = 2; i <=5; i++) {
		uf[i-2] = new UnitFrame(cl[i]);
		uf[i-2]->setPosition(Vec2(0, borderline-180+(i-2)*-(90*1.6f)));
		uf[i - 2]->setScale(1.6f);
		this->addChild(uf[i-2]);
	}
	bf = new BossFrame(cl[0]);
	bf->setScale(1.6f);
	bf->setPosition(Vec2(visibleSize.width / 2, borderline + 80));
	this->addChild(bf);

	HealSkillFactory hsf;
	hsf.initAllSkills();
	Skill** sl = hsf.getSkillsList(SKILLNUM);
	SkillFrame *sf[SKILLNUM];
	borderline = visibleSize.height - 240;
	for (int i = 0; i < SKILLNUM; i++) {
		sf[i] = new SkillFrame(sl[i]);
		sf[i]->_button->setContentSize(Size(100, 80));
		sf[i]->_button->setAnchorPoint(Vec2(0, 1));
		sf[i]->_button->setPosition(Vec2(10, 80 * SKILLNUM + i*-80));
		sf[i]->_button->setTag(i);
		cl[1]->mySkillSet.push_back(sl[i]);
		this->skillBtnPosition[i] = sf[i]->_button->getPosition();
		scv->addChild(sf[i]->_button);
	}
	this->addChild(scv);
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

void Raid::moveBossFrame(float fd) {
	auto move1 = MoveBy::create(fd/2,Point(10,0));
	auto move2 = MoveBy::create(fd / 2, Point(-10, 0));
	auto action = Sequence::create(move1, move2, NULL);
	bf->_icon->runAction(action);
}
void Raid::playingFunc(float fd) {
	static double flowedTime=0.0;
	//character skill& do attack
	for (int i = 0; i < 6; i++) {
		if (i == 1) continue;
		if (!cl[i]->checkDie()&&cl[i]->_timer<=flowedTime) {
			int skillNum = cl[i]->getUsableSkill();
			Skill *skill=cl[i]->mySkillSet[skillNum];
			if (skill->getType() == buff) {
				skill->activate(cl, *cl[i],1);
			}
			else if (skill->getType() == debuff) {
				skill->activate(cl, *cl[i], -1);
			}
			else {
				skill->activate(cl, *cl[i]);
			}
			SkillInfo _tSkillInfo;
			_tSkillInfo.cl = cl[i];
			_tSkillInfo.skillNum = skillNum;
			this->skillStorage.push_back(_tSkillInfo);
			cl[i]->_timer += cl[i]->getStatus()->getSpeed();
		}
	}
	flowedTime += fd;
}

void Raid::skillCoolDown(float fd) {
	std::list<SkillInfo>::iterator it = this->skillStorage.begin();
	if (it == this->skillStorage.end()) return;
	std::list<SkillInfo>::iterator it2 = std::next(it);
	while (it != skillStorage.end()) {
		Skill *skill = it->cl->mySkillSet[it->skillNum];
		skill->_cooldown -= fd * 1000;
		if (skill->able()) {
			if (skill->getType() == buff) {
				skill->activate(cl, *it->cl, -1);
			}
			else if (skill->getType() == debuff) {
				skill->activate(cl, *it->cl, 1);
			}
			skillStorage.erase(it);	
		}
		it = it2;
		if (it != skillStorage.end())it2 = std::next(it);
	}
}
void Raid::frameUpdate(float fd) {
	for (int i = 0; i < 4; i++)
		uf[i]->updateAll();
	bf->updateAll();
}
void Raid::checkGameOver(float fd) {
	if (cl[0]->checkDie()){
		this->unschedule(schedule_selector(Raid::moveBossFrame));
		this->unschedule(schedule_selector(Raid::playingFunc));
		this->unschedule(schedule_selector(Raid::skillCoolDown));
		this->unschedule(schedule_selector(Raid::frameUpdate));
		this->unschedule(schedule_selector(Raid::checkGameOver));
		OHDialog popup(Size(500,200),"system","you win!");
		popup.cancelBtn->setVisible(false);
		popup.okBtn->addTouchEventListener([&](Ref *sender, ui::Button::TouchEventType e) {
			if (e == ui::Button::TouchEventType::ENDED) {
				ui::Button *btn = (ui::Button*)sender;
				btn->getParent()->removeFromParentAndCleanup(true);
				/*drop item setting */
				Director::getInstance()->popScene();
			}
		});
		popup.addedTo(this);
		CCLOG("game end! win");
	}
	else if ((cl[2]->checkDie() && cl[3]->checkDie() && cl[4]->checkDie() && cl[5]->checkDie())) {
		this->unschedule(schedule_selector(Raid::moveBossFrame));
		this->unschedule(schedule_selector(Raid::playingFunc));
		this->unschedule(schedule_selector(Raid::skillCoolDown));
		this->unschedule(schedule_selector(Raid::frameUpdate));
		this->unschedule(schedule_selector(Raid::checkGameOver));
		OHDialog popup(Size(500, 200), "system", "you lose!");
		popup.cancelBtn->setVisible(false);
		popup.okBtn->addTouchEventListener([](Ref *sender, ui::Button::TouchEventType e) {
			if (e == ui::Button::TouchEventType::ENDED) {
				ui::Button *btn = (ui::Button*)sender;
				btn->getParent()->removeFromParentAndCleanup(true);
				Director::getInstance()->popScene();
			}
		});
		popup.addedTo(this);
		CCLOG("game end! lose");
	}
}