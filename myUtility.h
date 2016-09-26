/*
FileName: 	myUtility.h
Revision: 	2016/08/23 by PorcaM
*/

#pragma once
#include <cstdio>
#include "parts/MyRGB.h"

#define DAMAGE_FOMULA(a, b) (1 + calcRGBFomula(a.getStatus()->getMyRGBDamage(), b->getStatus()->getMyRGBDefence()))*\
(a.getStatus()->getDamage() - b->getStatus()->getDefence() / 4) * _factor / getTime()

int 	isRange(char *, int, int, int);
float 	calcRGBFomula(MyRGB rgbAttack, MyRGB rgbBeaten);