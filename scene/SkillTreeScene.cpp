/* ============================================================
FileName:	SkillTreeScene.cpp
Revision:	2016/09/11 by PorcaM
void SkillTreeScene::InitLayer(){

}
Modified: 	2016/10/05 by PorcaM
============================================================ */
#include <string>
using std::string;

#include "SkillTreeScene.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
#include "scene/SkillTreeComponent/PlayerInfo.h"
#include "scene/SkillTreeComponent/PlayerInfoFrame.h"
#include "scene/SkillTreeComponent/SkillInfo.h"
#include "scene/SkillTreeComponent/SkillTreeFrame.h"

Scene* SkillTreeScene::createScene(Data data)
{
	auto scene = Scene::create();
	auto layer = SkillTreeScene::create();
	layer->set_data(data);
	layer->OHInit();
	scene->addChild(layer);
	return scene;
}
void SkillTreeScene::set_data(Data data) {
	if (data.player == NULL) {
		assert(false);
	}
	data_ = data;
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

/* ============================================================
	Custom functions
============================================================ */
void SkillTreeScene::InitLayer(){
	skilltree_layer_ = Layer::create();
	float offset = 1.6f;
	float width = visible_size_.width/2*offset;
	float height = visible_size_.height/2*offset;
	skilltree_layer_->setPosition(Vec2(width, height));
	skilltree_layer_->setScale(offset);
	this->addChild(skilltree_layer_);
	return;
}
void SkillTreeScene::InitOuterFrame(){
	/* Outline */
	auto outline = Sprite::create("images/skilltree/outline.png");
	skilltree_layer_->addChild(outline);
	/* Title */
	auto title = Sprite::create("images/skilltree/title.png");
	title->setPosition(Vec2(0, 250));
	skilltree_layer_->addChild(title);
	/* Close button */
	close_btn_ = ui::Button::create("images/skilltree/btn_close.png");
	close_btn_->setAnchorPoint(Vec2(0.5f, 1.0f));
	close_btn_->setPosition(Vec2(268, 47));
	title->addChild(close_btn_);
	return;
}
void SkillTreeScene::OHInit(){
	visible_size_ = Director::getInstance()->getVisibleSize();
	set_backgorund(Color4F(1, 1, 1, 1));
	InitLayer();
	InitOuterFrame();
	/* ============================================================
	Player Information Frame
	============================================================ */
	auto skillInfo = new SkillInfo();
	Player *player = data_.player;
	SkillTree *stree = skillInfo->get_skilltree_by_type((SkillInfo::Type)0);
	stree->Load(player->skilltreeData[0]); // [TODO] read :158
	auto slot = new SkillSlot();
	slot->Assign(player->mySkillSet);
	auto playerInfo = new PlayerInfo(player->skillPoint, slot);
	auto playerInfoFrame = new PlayerInfoFrame(playerInfo);
	playerInfoFrame->setPositionY(-270);
	skilltree_layer_->addChild(playerInfoFrame);
	/* ============================================================
	Skilltree Frame
	============================================================ */
	auto skillTreeFrame = new SkillTreeFrame(skillInfo, playerInfo, playerInfoFrame);
	skillTreeFrame->setPositionY(185);
	skilltree_layer_->addChild(skillTreeFrame);
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
		skilltree_layer_->addChild(tab[i]);
	}
	for (int i = 0; i < 3; i++) {
		tab[i]->addTouchEventListener([=](Ref *pSender, ui::Button::Widget::TouchEventType type) {
			printf(((ui::Button*)pSender)->getName().c_str());
			skillTreeFrame->UpdateByType((Skill::Type)i);
		});
	}
	close_btn_->addTouchEventListener([=](
			Ref *pSender,
			ui::Button::Widget::TouchEventType type) {
		if (type == ui::Button::Widget::TouchEventType::ENDED) {
			auto list = slot->get_list();
			auto it = list.begin();
			player->mySkillSet.assign(it, list.end());
			Director::getInstance()->popScene();
			// [TODO] When implement buff and debuff, then changed
			SkillTree *stree = skillInfo->get_skilltree_by_type((SkillInfo::Type)0);
			int data = stree->Save();
			player->skilltreeData[0] = data;
		}
	});
	return;
}

void SkillTreeScene::set_backgorund(Color4F color) {
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
