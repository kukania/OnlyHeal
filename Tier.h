#pragma once
#include <random>

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
	short setLevel(short *);
	short getLevel();
	short setLabel(short);
	short setLabel(short *);
	short* getLabel();

	int getValue();
	int setValue();

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
		if (level + arr[num] > 80)
			level = 80;
		else if (level + arr[num] < 0)
			level = 0;
		else
			level += arr[num];
		temp.setLevel(level);
		return temp;
	}
};