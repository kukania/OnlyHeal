/*
FileName:	UnitFrameFactory.h
Revision:	2016/08/25 by PorcaM
*/

#pragma once

#include "unitFrame.h"

class UnitFrameFactory {
public:
	static UnitFrame *getUnitFrame(Character *);
};