#include "scene/ConsumableComponent.h" 
#include "../ConvertKorean.h"
#include"OHDialog.h"
ConsumableComponent::ConsumableComponent(Size s,Consumable* c) {
	switch (c->getType()) {
	case Consumable::CType::DAMAGE:
		this->container = ui::Button::create("images/helloworld/box.png", "images/helloworld/box.png", "images/helloworld/box.png");
		break;
	case Consumable::CType::DEFENCE:
		this->container = ui::Button::create("images/helloworld/box.png", "images/helloworld/box.png", "images/helloworld/box.png");
		break;
	case Consumable::CType::MAXHP:
		this->container = ui::Button::create("images/helloworld/box.png", "images/helloworld/box.png", "images/helloworld/box.png");
		break;
	case Consumable::CType::SP:
		this->container = ui::Button::create("images/helloworld/box.png", "images/helloworld/box.png", "images/helloworld/box.png");
		break;
	}
	this->container->setScale9Enabled(true);
	this->container->setAnchorPoint(Point(0, 1));
	this->container->setSize(s);
	item = c;
	this->container->addTouchEventListener([c](Ref * sender, ui::Button::TouchEventType e) {
		ui::Button * btn = (ui::Button*)sender;
		switch (e) {
		case ui::Button::TouchEventType::ENDED:
			OHDialog * temp = new OHDialog(Size(400,300),"º¹¿ë?",c->toString().c_str());
			temp->addedTo(btn->getParent()->getParent()->getParent()->getParent());
			break;
		}
	});
}
void ConsumableComponent::addedTo(Node *p) {
	p->addChild(this->container);
}
void ConsumableComponent::setPosition(Point p) {
	this->container->setPosition(p);
}