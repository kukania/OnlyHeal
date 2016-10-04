/* ============================================================
FileName:	SkillTreeScene.cpp
Revision:	2016/09/11 by PorcaM
Modified: 	2016/09/22 by PorcaM
============================================================ */

#include "SkillTreeScene.h"
#include "ui/CocosGUI.h"
//#include "SkillTreeComponent/SkillTreeFrame.h"
#include "scene/SkillTreeComponent/PlayerInfo.h"
#include "scene/SkillTreeComponent/PlayerInfoFrame.h"
#include "scene/SkillTreeComponent/SkillInfo.h"
#include "scene/SkillTreeComponent/SkillTreeFrame.h"
#include <string>
using std::string;
USING_NS_CC;

Scene* SkillTreeScene::createScene(InputData inputdata)
{
	auto scene = Scene::create();
	auto layer = SkillTreeScene::create();
	layer->set_inputdata(inputdata);
	layer->myInit();
	scene->addChild(layer);
	return scene;
}
void SkillTreeScene::set_inputdata(InputData inputdata) {
	if (inputdata.player == NULL) {
		assert(false);
	}
	inputdata_ = inputdata;
	return;
}
bool SkillTreeScene::init()
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
		CC_CALLBACK_1(SkillTreeScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	return true;
}
void SkillTreeScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif 
}

void SkillTreeScene::setBackground(Color4F color) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto backGround = DrawNode::create();
	Vec2 corners[4] = {
		Vec2(0, visibleSize.height),
		Vec2(visibleSize.width, visibleSize.height),
		Vec2(visibleSize.width, 0),
		Vec2(0, 0)
	};
	backGround->drawPolygon(corners, 4, color, 0, color);
	this->addChild(backGround);
	return;
}

void SkillTreeScene::myInit(){
	auto visibleSize = Director::getInstance()->getVisibleSize();
	/* ============================================================
	Below codes are writed by PorcaM.
	Generate SkillTree Layer.
	============================================================ */
	setBackground(Color4F(1, 1, 1, 1));
	/* ============================================================
	Layer
	Include all elements of this scene.
	============================================================ */
	auto SkillTreeLayer = Layer::create();
	SkillTreeLayer->setPosition(Vec2(visibleSize.width / 2 * 1.6, visibleSize.height / 2 * 1.6));
	SkillTreeLayer->setScale(1.6f);
	this->addChild(SkillTreeLayer);
	/* ============================================================
	Outline
	============================================================ */
	auto outline = Sprite::create("images/skilltree/outline.png");
	SkillTreeLayer->addChild(outline);
	/* ============================================================
	Title
	============================================================ */
	auto title = Sprite::create("images/skilltree/title.png");
	title->setPosition(Vec2(0, 250));
	SkillTreeLayer->addChild(title);
	auto closeBtn = ui::Button::create("images/skilltree/btn_close.png");
	closeBtn->addTouchEventListener([&](Ref *pSender, ui::Button::Widget::TouchEventType type) {
		printf("Touch event type: %d\n", type);
		Director::getInstance()->popScene();
	});
	closeBtn->setAnchorPoint(Vec2(0.5f, 1.0f));
	closeBtn->setPosition(Vec2(268, 47));
	title->addChild(closeBtn);
	/* ============================================================
	Player Information Frame
	============================================================ */
	auto skillInfo = new SkillInfo();
	Player *player = inputdata_.player;
	auto slot = new SkillSlot();
	slot->Assign(player->mySkillSet);
	auto playerInfo2 = new PlayerInfo(20, slot);
	auto pif = new PlayerInfoFrame(playerInfo2);
	pif->setPositionY(-270);
	SkillTreeLayer->addChild(pif);
	/* ============================================================
	Skilltree Frame
	============================================================ */
	auto skillTreeFrame = new SkillTreeFrame(skillInfo, playerInfo2, pif);
	skillTreeFrame->setPositionY(185);
	SkillTreeLayer->addChild(skillTreeFrame);
	/* ============================================================
	Tabs
	============================================================ */
	ui::Button* tab[3];
	string num[3] = { "1", "2", "3" };
	for (int i = 0; i < 3; i++) {
		string path = "images/skilltree/tab" + num[i] + ".png";
		tab[i] = ui::Button::create(path.c_str());
		tab[i]->setAnchorPoint(Vec2(0.5f, 0));
		tab[i]->setPosition(Vec2(92 * (i - 1), 185));
		tab[i]->setName("tab" + num[i]);
		SkillTreeLayer->addChild(tab[i]);
	}
	for (int i = 0; i < 3; i++) {
		tab[i]->addTouchEventListener([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
			printf(((ui::Button*)pSender)->getName().c_str());
			skillTreeFrame->UpdateByType((Skill::Type)i);
		});
	}
	closeBtn->addTouchEventListener([=](
			Ref *pSender,
			ui::Button::Widget::TouchEventType type) {
		auto list = slot->get_list();
		auto it = list.begin();
		player->mySkillSet.assign(it, list.end());
	});
	return;
}