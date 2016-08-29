/*
FileName:	UnitFrameFactory.cpp
Revision:	2016/08/25 by PorcaM
*/

#include "UnitFrameFactory.h"

UnitFrame *UnitFrameFactory::getUnitFrame(Character *character) {
	return new UnitFrame(character);
}