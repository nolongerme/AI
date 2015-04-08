#include "Armor.h"


Armor::Armor(ARMOR_TYPE type, float v)
{
	if (v > 10)
		v = 10;
	if (v < 1)
		v = 1;
	type = armorType;
	v = value;
}


Armor::~Armor()
{
}

