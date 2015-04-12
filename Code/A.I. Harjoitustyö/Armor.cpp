#include "Armor.h"


Armor::Armor(ARMOR_TYPE type, float v)
{

	armorType = type;
	value = v;

	if (v > 10)
		v = 10;
	if (v < 1)
		v = 1;
}


Armor::~Armor()
{
}

