/*
FileName:	SkillTreeScene.cpp
Revision:	2016/09/11 by PorcaM
*/

#include "SkillTreeScene.h"
#include "ui/CocosGUI.h"

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

	/*
	Below codes are writed by PorcaM
	*/
	setBackground(Color4F(1, 1, 1, 1));

	auto outline = Sprite::create ("images/skilltree/outline.png");
	outline->setScale (1.6f);
	outline->setAnchorPoint (Vec2 (0.5f, 0.5f));
	outline->setPosition (Vec2 (visibleSize.width/2, visibleSize.height/2));
	this->addChild (outline);


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