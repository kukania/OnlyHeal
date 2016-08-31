#include "statusHexa.h"

#include<cmath>
StatusHexa::StatusHexa(float value) {
	this->y=this->x = 0.0f;
	this->value = value;
	this->corners[0] = Vec2(this->x+(-value / 2) * sqrt(3),this->y+value / 2);
	this->corners[1] = Vec2(this->x, this->y+value);
	this->corners[2] = Vec2(this->x+value / 2 * sqrt(3), this->y + value / 2);
	this->corners[3]= Vec2(this->x+value / 2 * sqrt(3), this->y +( -value / 2));
	this->corners[4] = Vec2(this->x,this->y+ (-value));
	this->corners[5] = Vec2(this->x+(-value / 2 * sqrt(3)),this->y+( -value / 2));
}
void StatusHexa::setSize(float value) {
	this->value = value;
	this->corners[0] = Vec2(this->x + (-value / 2) * sqrt(3), this->y + value / 2);
	this->corners[1] = Vec2(this->x, this->y + value);
	this->corners[2] = Vec2(this->x + value / 2 * sqrt(3), this->y + value / 2);
	this->corners[3] = Vec2(this->x + value / 2 * sqrt(3), this->y + (-value / 2));
	this->corners[4] = Vec2(this->x, this->y + (-value));
	this->corners[5] = Vec2(this->x + (-value / 2 * sqrt(3)), this->y + (-value / 2));
}
void StatusHexa::setPosition(float x, float y) {
	this->x = x; this->y = y;
	this->corners[0] = Vec2(this->x + (-value / 2) * sqrt(3), this->y + value / 2);
	this->corners[1] = Vec2(this->x, this->y + value);
	this->corners[2] = Vec2(this->x + value / 2 * sqrt(3), this->y + value / 2);
	this->corners[3] = Vec2(this->x + value / 2 * sqrt(3), this->y + (-value / 2));
	this->corners[4] = Vec2(this->x, this->y + (-value));
	this->corners[5] = Vec2(this->x + (-value / 2 * sqrt(3)), this->y + (-value / 2));
}
void StatusHexa::setStatusVertex(Character *c) {
	float setNum = value / 255;
	this->statusVertex[0] = Vec2(-c->getStatus()->getMyRGBDamage().getR()*setNum / 2 * sqrt(3), c->getStatus()->getMyRGBDamage().getR()*setNum / 2);
	this->statusVertex[1] = Vec2(0, c->getStatus()->getMyRGBDefence().getR()*setNum / 2);
	this->statusVertex[2] = Vec2(c->getStatus()->getMyRGBDamage().getG()*setNum / 2 * sqrt(3), c->getStatus()->getMyRGBDamage().getG()*setNum / 2);
	this->statusVertex[3] = Vec2(c->getStatus()->getMyRGBDefence().getG()*setNum / 2 * sqrt(3), -c->getStatus()->getMyRGBDefence().getG()*setNum/2);
	this->statusVertex[4] = Vec2(0, -c->getStatus()->getMyRGBDamage().getB()*setNum/2);
	this->statusVertex[5] = Vec2(-c->getStatus()->getMyRGBDefence().getB()*setNum / 2 * sqrt(3), -c->getStatus()->getMyRGBDefence().getB()*setNum / 2);
}
