#include"ItemComponent.h"
#include"../ConvertKorean.h"

ItemComponent::ItemComponent(Item *input,Size size) {
	content = Layer::create();
	content->setContentSize(size);
	this->size = size;

	spr = Sprite::create("images/helloworld/box.png");
	spr->setScaleX(80.0f/spr->getContentSize().width);
	spr->setScaleY(80.0f / spr->getContentSize().height);
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
	
	auto txt_ = Label::createWithTTF(_AtoU8(input->getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
	txt_->setPosition(Point(size.width/2,size.height/2-3));
	txt_->setColor(Color3B(255, 255, 255));
	content->addChild(txt_);
	
	auto txt_2 = Label::createWithTTF(_AtoU8(input->getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
	txt_2->setPosition(Point(size.width / 2+3, size.height / 2));
	txt_2->setColor(Color3B(255, 255, 255));
	content->addChild(txt_2);
	
	auto txt_3 = Label::createWithTTF(_AtoU8(input->getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
	txt_3->setPosition(Point(size.width / 2-3, size.height / 2));
	txt_3->setColor(Color3B(255, 255, 255));
	content->addChild(txt_3);
	
	auto txt_4 = Label::createWithTTF(_AtoU8(input->getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
	txt_4->setPosition(Point(size.width / 2, size.height / 2+3));
	txt_4->setColor(Color3B(255, 255, 255));
	content->addChild(txt_4);

	auto txt2 = Label::createWithTTF(_AtoU8(input->getTier().getTierByString().c_str()), "fonts/sdCrayon.ttf", 32);
	txt2->setPosition(Point(size.width / 2, size.height / 2));
	txt2->setColor(Color3B(0, 0, 0));
	content->addChild(txt2);
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
	labelLayer->setName("New");
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
	labelLayer->setName("Equiped");
	content->addChild(labelLayer);
}