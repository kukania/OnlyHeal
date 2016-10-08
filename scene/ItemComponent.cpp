#include"ItemComponent.h"
#include"../ConvertKorean.h"

ItemComponent::ItemComponent(Item *input,Size size) {
	content = Layer::create();
	content->setContentSize(size);
	this->size = size;

	spr = Sprite::create("images/helloworld/box.png");
	spr->setScale(1.1f);
	spr->setPosition(Point(size.width / 2, size.height / 2));
	spr->setColor(Color3B(input->getMyRGB().getR(), input->getMyRGB().getG(), input->getMyRGB().getB()));
	content->addChild(spr);

	this->btn = ui::Button::create();
	btn->setTouchEnabled(true);
	btn->setSwallowTouches(false);
	btn->setScale9Enabled(true);
	btn->setPosition(Point(size.width / 2, size.height / 2));
	btn->setContentSize(size);
	content->addChild(btn);
	
	auto txt = Label::createWithTTF(_AtoU8(input->getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
	txt->setPosition(Point(size.width/2,size.height/2));
	txt->setColor(Color3B(0, 0, 0));
	content->addChild(txt);
}
void ItemComponent::setNew() {
	auto newLabel = Label::createWithTTF("New", "fonts/sdCrayon.ttf", 30);
	Size eqlSize = newLabel->getContentSize();
	auto labelLayer = LayerColor::create(Color4B(255, 255, 0, 255), eqlSize.width, eqlSize.height);
	newLabel->setColor(Color3B(0, 0, 0));
	newLabel->setAnchorPoint(Point(0, 0));
	newLabel->setPosition(Point(0, 0));
	labelLayer->addChild(newLabel);
	labelLayer->setPosition(Point(8, 25));
	content->addChild(labelLayer);
}
void ItemComponent::setEquiped() {
	auto equipedLabel = Label::createWithTTF(_AtoU8("ÀåÂøÁß"), "fonts/sdCrayon.ttf", 24);
	Size eqlSize = equipedLabel->getContentSize();
	auto labelLayer = LayerColor::create(Color4B(255, 0, 255, 255), eqlSize.width, eqlSize.height);
	equipedLabel->setColor(Color3B(0, 0, 0));
	equipedLabel->setAnchorPoint(Point(0, 0));
	equipedLabel->setPosition(Point(0, 0));
	labelLayer->addChild(equipedLabel);
	labelLayer->setPosition(Point(8, 25));
	content->addChild(labelLayer);
}