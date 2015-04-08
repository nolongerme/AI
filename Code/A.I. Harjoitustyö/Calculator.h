#pragma once
#include "BodyPart.h"
#include "Armor.h"
#include "Weapon.h"
static class Calculator
{
public:
	Calculator();
	~Calculator();

	float probability(BodyPart hitPart, float dexterity);
	float damage(Armor armor, Weapon weapon);

private:
	float calcTypeEfficiency(ARMOR_TYPE, WEAPON_TYPE);
};

