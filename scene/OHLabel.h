#pragma once
#include<string>
#include<iostream>
#include"cocos2d.h"

USING_NS_CC;
using namespace std;

class OHLabel {
public:
	OHLabel(Size,string,int);
	void setString(string );
	void addedTo(Node *);
	void moveBy(Point p);
	void setPosition(Point p);
	void setAnchorPoint(Point p);
private:
	Label *background[4];
	Label *content;
};