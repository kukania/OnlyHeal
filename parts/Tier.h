#pragma once
#include <random>
#include<string>
#define MAX_LEVEL 80
#define MAX_LABEL 2

class Tier {
private:
	short	label[4];
	short	level;
	int		value;
public:
	Tier() {
		short temp = 0;
		setLevel(temp);
	}
	Tier(short);
	Tier(short*);
	short setLevel(short);
	short getLevel();
	short setLabel(short *);
	short* getLabel();

	int getValue();
	int setValue();
	std::string	getTierByString();
	static short label2level(short *_label) {
		short ret = 0;
		for (int i = 0; i < 4; i++) {
			ret *= 3;
			ret += _label[i];
		}
		return ret;
	}
	static void level2label(short _level, short *_label) {
		for (int i = 0; i < 4; i++) {
			_label[i] = _level % 3;
			_level /= 3;
		}
		return;
	}
	static Tier getSimillarTier(int level) {
		short arr[5] = { -2,-1,-0,1,2 };
		Tier temp(level);
		short num = rand() % 5;
		if (level + arr[num] > MAX_LEVEL)
			level = MAX_LEVEL;
		else if (level + arr[num] < 0)
			level = 0;
		else
			level += arr[num];
		temp.setLevel(level);
		return temp;
	}
};