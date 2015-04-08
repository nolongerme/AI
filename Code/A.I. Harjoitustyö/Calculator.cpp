#include "Calculator.h"


Calculator::Calculator()
{
}

float Calculator::probability(BodyPart hitPart, float dexterity)
{
	return BodyPart.chanceToHit*dexterity/10;
}

float Calculator::damage(Armor armor, Weapon weapon, float strength)
{
	typeEfficiency(armor.type, weapon.type) * damageValue(armor.value, weapon.damage, strength);
	
}

float Calculator::damageValue(float armorValue, float weaponDamage, float strength)
{
	return weaponDamage * strength * 1/armorValue * 0.1f;
}

float Calculator::typeEfficiency(ARMOR_TYPE armorType, SWORD_TYPE swordType)
{
	ArmorEfficiency eff;

	switch(armorType)
	{
	case PLATE:
		eff.againstClub = 0.8;
		eff.againstSpear = 1;
		eff.againstSword = 1.2;
		break;
	case CHAIN:
		eff.againstClub = 0.8;
		eff.againstSpear = 1.2;
		eff.againstSword = 1;
		break;
	case LEATHER:
		eff.againstClub = 1;
		eff.againstSpear = 0.8;
		eff.againstSword = 1.2;
		break;
	}

	switch (swordType)
	{
	case SWORD:
		return eff.againstSword;
		break;
	case SPEAR:
		return eff.againstSpear;
		break;
	case CLUB:
		return eff.againstClub;
		break;
	}
}



Calculator::~Calculator()
{
}
