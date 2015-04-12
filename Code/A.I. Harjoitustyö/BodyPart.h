#pragma once

#include "Armor.h"

enum BODY_PART_SIZE
{
	SMALL,
	MEDIUM,
	LARGE
};

class BodyPart
{
public:
	BodyPart(BODY_PART_SIZE bodyPartSize);
	BodyPart(){}; //jumalauta
	~BodyPart();

	Armor* armor;
	float chanceToHit;
};

