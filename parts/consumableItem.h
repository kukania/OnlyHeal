#pragma once
#include"../characters/Character.h"
#include<string>
#include<list>
class Consumable {
public:
	enum CType{
		MAXHP,DAMAGE,DEFENCE,SP
	};
	Consumable() {}
	Consumable(CType a, int b) {
		this->type = a; this->value = b;
	}
	Consumable(Character *, CType, int);
	Consumable(Character *, CType,int,string,string);
	void consume();
	string toString();
	void setName(string);
	void setContent(string);
	void setOwner(Character *);
	CType getType();
	std::list<Consumable*>::iterator it;
	bool isNew;
	string getFileString();/*FTYPE CTYPE VALUE*/
	static Consumable* consumableByString(Character *owner, string fstring);
private:
	CType type;
	int value;
	string name;
	string contents;
	Character * owner;
};