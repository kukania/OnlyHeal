#pragma once
#include"OHLabel.h"
#include"../ConvertKorean.h"
OHLabel::OHLabel(Size size2,string in, int size) {
	Size tempS = size2;
	content = Label::createWithTTF(_AtoU8(in.c_str()), "fonts/sdCrayon.ttf", size, tempS, TextHAlignment::CENTER);
	content->setPosition(Point(tempS.width / 2, tempS.height / 2));
	content->setAnchorPoint(Point(0.5, 0.5));
	content->setColor(Color3B(0,0,0));
	for (int i = 0; i < 4; i++) {
		background[i] = Label::createWithTTF(_AtoU8(in.c_str()), "fonts/sdCrayon.ttf", size, tempS, TextHAlignment::CENTER);
		background[i]->setAnchorPoint(Point(0.5, 0.5));
		switch (i) {
		case 0:
			background[i]->setPosition(Point(tempS.width / 2+3, tempS.height / 2));
			break;
		case 1:
			background[i]->setPosition(Point(tempS.width / 2-3, tempS.height / 2));
			break;
		case 2:
			background[i]->setPosition(Point(tempS.width / 2, tempS.height / 2+3));
			break;
		case 3:
			background[i]->setPosition(Point(tempS.width / 2, tempS.height / 2-3));
			break;
		}
	}
}
void OHLabel::setString(string in) {
	content->setString(in);
	for (int i = 0; i < 4; i++) background[i]->setString(in);
}
void OHLabel::moveBy(Point p) {
	content->setPosition(content->getPosition().x + p.x, content->getPosition().y + p.y);
	for (int i = 0; i < 4; i++) background[i]->setPosition(background[i]->getPosition().x + p.x, background[i]->getPosition().y + p.y);
}
void OHLabel::addedTo(Node *p) {
	for (int i = 0; i < 4; i++) p->addChild(background[i]);
	p->addChild(this->content);
}
void OHLabel::setPosition(Point p) {
	for (int i = 0; i < 4; i++) background[i]->setPosition(p);
	this->content->setPosition(p);
}
void OHLabel::setAnchorPoint(Point p) {
	for (int i = 0; i < 4; i++) background[i]->setAnchorPoint(p);
	this->content->setAnchorPoint(p);
}