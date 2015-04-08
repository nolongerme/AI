#pragma once
#include "BodyPart.h"
#include "Armor.h"
#include "Weapon.h"
#include <math.h>

struct ArmorEfficiency
{
	float againstSword;
	float againstSpear;
	float againstClub;
};


static class Calculator
{
public:
	Calculator();
	~Calculator();

	float probability(BodyPart hitPart, float dexterity);
	float damage(Armor armor, Weapon weapon, float strength);

private:
	float typeEfficiency(ARMOR_TYPE armorType, WEAPON_TYPE weaponType);
	float damageValue(float armorValue, float weaponDamage, float strength);
	float armorEfficiency(ARMOR_TYPE armorType);
};


