#pragma once
#include "cocos2d.h"
#include "characters/Character.h"
USING_NS_CC;
class StatusHexa {
public:
	float x, y,value;
	Vec2 corners[6];
	Vec2 statusVertex[6];
	StatusHexa() {}
	StatusHexa(float value);
	void setSize(float value);
	void setPosition(float x, float y);
	void setStatusVertex(Character *user);
};