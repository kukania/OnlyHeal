/* ============================================================
FileName:	SkillTreeScene.cpp
Revision:	2016/09/11 by PorcaM
Modified: 	2016/09/22 by PorcaM
============================================================ */

#include "SkillTreeScene.h"
#include "ui/CocosGUI.h"
#include "SkillTreeComponent/SkillTreeFrame.h"
#include "SkillTreeComponent/PlayerInfoFrame.h"
#include <string>
using std::string;
USING_NS_CC;

Scene* SkillTreeScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SkillTreeScene::create();
	scene->addChild(layer);
	return scene;
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

	/* ============================================================
		Below codes are writed by PorcaM.
		Generate SkillTree Layer.
	============================================================ */
	setBackground (Color4F (1, 1, 1, 1));
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
	auto outline = Sprite::create ("images/skilltree/outline.png");
	SkillTreeLayer->addChild (outline);
	/* ============================================================
		Title
	============================================================ */
	auto title = Sprite::create ("images/skilltree/title.png");
	auto closeBtn = ui::Button::create ("images/skilltree/btn_close.png");
	closeBtn->addTouchEventListener([&](Ref *pSender, ui::Button::Widget::TouchEventType type) {
		printf ("Touch event type: %d\n", type);
		Director::getInstance()->popScene();
	});
	closeBtn->setAnchorPoint (Vec2 (0.5f, 1.0f));
	closeBtn->setPosition (Vec2 (268, 47));
	title->addChild (closeBtn);
	title->setPosition (Vec2 (0, 250));
	SkillTreeLayer->addChild (title);
	/* ============================================================
		Tabs
	============================================================ */
	ui::Button* tab[3];
	string num[3] = { "1", "2", "3" };
	for (int i = 0; i < 3; i++){
		string path = "images/skilltree/tab" + num[i] + ".png";
		tab[i] = ui::Button::create (path.c_str ());
		tab[i]->setAnchorPoint (Vec2 (0.5f, 0));
		tab[i]->setPosition (Vec2 (92*(i-1), 185));
		tab[i]->setName ("tab"+num[i]);
		SkillTreeLayer->addChild (tab[i]);
	}
	/* ============================================================
		Skilltree Frame
	============================================================ */
	SkillTreeFrame* stf = new SkillTreeFrame ();
	SkillTreeLayer->addChild (stf->get_scrollview());
	/* ============================================================
		Player Information Frame
	============================================================ */
	auto pif = new PlayerInfoFrame();
	pif->setPositionY(-270);
	SkillTreeLayer->addChild(pif);

	for (int i = 0; i < 3; i++){
		tab[i]->addTouchEventListener ([&, stf, i] (Ref *pSender, ui::Button::Widget::TouchEventType type){
			printf (((ui::Button*)pSender)->getName ().c_str ());
			stf -> InitWithType ((Skill::Type)i);
		});
	}
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