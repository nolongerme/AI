#pragma once
#include <iostream>

using namespace std;

enum ARMOR_TYPE {CHAINMAIL, PLATE, LEATHER};

class Armor
{
public:
	Armor(ARMOR_TYPE type, float v);
	~Armor();

	float value;
	ARMOR_TYPE armorType;

};

