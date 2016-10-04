#include "scene/ConsumableComponent.h" 
#include "../ConvertKorean.h"
#include"OHDialog.h"
ConsumableComponent::ConsumableComponent(Size s,ConsumableLayer * cLP,Consumable* c) {
	switch (c->getType()) {
	case Consumable::CType::DAMAGE:
		this->container = ui::Button::create("images/consumable/damage.png", "images/consumable/damage.png", "images/consumable/damage.png");
		break;
	case Consumable::CType::DEFENCE:
		this->container = ui::Button::create("images/consumable/def.png", "images/consumable/def.png", "images/consumable/def.png");
		break;
	case Consumable::CType::MAXHP:
		this->container = ui::Button::create("images/consumable/hp.png", "images/consumable/hp.png", "images/consumable/hp.png");
		break;
	case Consumable::CType::SP:
		this->container = ui::Button::create("images/consumable/skill.png", "images/consumable/skill.png", "images/consumable/skill.png");
		break;
	}
	this->container->setScale9Enabled(true);
	this->container->setAnchorPoint(Point(0, 1));
	this->container->setSize(s);
	this->cLayer = cLP;
	item = c;
	this->container->addTouchEventListener([c](Ref * sender, ui::Button::TouchEventType e) {
		ui::Button * btn = (ui::Button*)sender;
		switch (e) {
		case ui::Button::TouchEventType::ENDED:
			OHDialog * temp = new OHDialog(Size(400,300),"º¹¿ë?",c->toString().c_str());
			temp->addedTo(btn->getParent()->getParent()->getParent()->getParent());
			temp->okBtn->addTouchEventListener([c,temp](Ref *sender, ui::Button::TouchEventType e) {
				c->consume();
				temp->dialogContent->removeFromParentAndCleanup(true);
			});
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
void ConsumableComponent::setCLayer(ConsumableLayer * p) {
	this->cLayer = p;
}