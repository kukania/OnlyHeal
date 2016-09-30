#include"ConsumableLayer.h"
#include"../ConvertKorean.h"
ConsumableLayer::ConsumableLayer(Size cSize, ConsumableInventory * inven, int column,int cellHeight) {
	this->contentsSize = cSize;
	this->inven = inven;
	this->column = column;

	content = LayerGradient::create(Color4B(255,255,255,255), Color4B(255, 255, 255, 255));
	cSize.width += 20; cSize.height += 80;
	content->setColor(Color3B(255, 255, 255));
	content->setContentSize(cSize);
	content->setPosition(Vec2(270-cSize.width/2, 490- cSize.height / 2));

	auto spr = ui::Scale9Sprite::create("images/party/partyFrame.png");
	spr->setScale9Enabled(true);
	spr->setAnchorPoint(Point(0, 1));
	spr->setPosition(Point(0, cSize.height));
	spr->setContentSize(cSize);
	content->addChild(spr);

	auto label = Label::createWithTTF(_AtoU8("¼Ò¸ğÇ°"), "fonts/sdCrayon.ttf", 40, Size(cSize.width/3, 50), TextHAlignment::CENTER, TextVAlignment::CENTER);
	label->setAnchorPoint(Point(0.5f, 1.0f));
	label->setPosition(Point(cSize.width / 2, cSize.height - 5));
	label->setColor(Color3B(0, 0, 0));
	content->addChild(label);

	auto btn = ui::Button::create("images/party/partyOutBtn.png");
	btn->setScale9Enabled(true);
	btn->setAnchorPoint(Point(1, 1));
	btn->setPosition(Point(cSize.width-5, cSize.height-5));
	btn->setContentSize(Size(50,50));
	btn->addTouchEventListener([](Ref*sender,ui::Button::TouchEventType e) {
		if (e == ui::Button::TouchEventType::ENDED) {
			Node* temp = ((Node*)sender)->getParent();
			temp->removeFromParent();
		}
	});
	content->addChild(btn);

	this->scv = ui::ScrollView::create();
	scv->setContentSize(Size(cSize.width-10,cSize.height-60));
	scv->setAnchorPoint(Point(1, 1));
	scv->setPosition(Point(cSize.width - 5, cSize.height - 55));
	scv->setBackGroundImageScale9Enabled(true);
	scv->setBackGroundImage("images/helloworld/rect.png");
	scv->setDirection(ui::ScrollView::Direction::VERTICAL);
	scv->setBounceEnabled(true);
	scv->setTouchEnabled(true);
	scv->setSwallowTouches(false);
	content->addChild(scv);

	this->cellWidth = cSize.width / column;
	this->cellHeight = cellHeight;
}
void ConsumableLayer::reloadData() {
	
}
void ConsumableLayer::addedTo(Node * parent) {
	parent->addChild(this->content);
}