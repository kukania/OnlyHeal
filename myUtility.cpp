/*
FileName:	myUtility.cpp
Revision:	2016/08/23 by PorcaM
*/

#include "myUtility.h"

// Return value: 0(Success), 1(Over), -1(Less)
int isRange(char *argName, int argValue, int max, int min) {
	int retVal = 0;
	if (min > argValue) {
		printf("[%s: %d] is little than MIN: %d\n", 
		argName, argValue, min);
		retVal = -1;
	}
	if (max < argValue) {
		printf("[%s: %d] is larger than MAX: %d\n", 
		argName, argValue, max);
		retVal = 1;
	}
	return retVal;
}

float calcRGBFomula(MyRGB rgbAttack, MyRGB rgbBeaten) {
	int tempR, tempG, tempB;
	tempR = rgbAttack.getR() - rgbBeaten.getR();
	if (0 > tempR) 	tempR = 0;
	tempG = rgbAttack.getG() - rgbBeaten.getG();
	if (0 > tempG) 	tempG = 0;
	tempB = rgbAttack.getB() - rgbBeaten.getB();
	if (0 > tempB) 	tempB = 0;
	return (tempR+tempG+tempB) / (3 * 255);
}