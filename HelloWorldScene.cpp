#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "skillinstance\SkillFactory.h"

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
    if ( !Layer::init() ){
        return false;
    }

	auto backGround = DrawNode::create();
	Vec2 corners[4] = {
		Vec2(0,100),
		Vec2(100,100),
		Vec2(100,0),
		Vec2(0,0)
	};
	backGround->drawPolygon(corners, 4, Color4F(1.0f, 0.3f, 0.3f, 1), 3, Color4F(1.0f, 0.3f, 0.3f, 1));
	this->addChild(backGround);
    return true;
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
