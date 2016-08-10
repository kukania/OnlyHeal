#pragma once
#include <random>

class Tier {
private:
	short	label[4];
	short	level;
	int		value;
public:
	Tier(short);
	Tier(short[]);
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
};