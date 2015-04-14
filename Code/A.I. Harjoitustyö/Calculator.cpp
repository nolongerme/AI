#include "Calculator.h"


Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

float Calculator::probability(BodyPart& hitPart, float dexterity)
{
	float chance = hitPart.chanceToHit;
	chance *= dexterity*0.1f;
	return chance;
}

float Calculator::damage(Armor& armor, Weapon& weapon, float strength)
{
		
		float efficiency = typeEfficiency(armor.armorType, weapon.weaponType);
		float dmg = damageValue(armor.value, weapon.damage, strength);

		float combined= efficiency*dmg;
		return combined;

}

HitSummary Calculator::hit(Character& attacker, Character& target, BodyPart& part)
{
	HitSummary summary;
	summary.damageDone = 0;
	summary.hitLanded = false;
	float probly = probability(part, attacker.dexterity);

	if(randomNumber()*0.01 <  probly && probly > 0)
	{
		summary.hitLanded = true;
		summary.damageDone = damage(*part.armor, *attacker.weapon, attacker.strength);

		// Täällä kohteen healthin erotus? Vai tapahtuuko jo jossain muualla?
		target.health = target.health - summary.damageDone;
		part.health = part.health - summary.damageDone;
		if (part.health < 0)
			part.health = 0;
	}

	return summary;
}

float Calculator::damageValue(float armorValue, float weaponDamage, float strength)
{
	return weaponDamage * strength * 1/armorValue * 0.1f;
}

float Calculator::typeEfficiency(ARMOR_TYPE armorType, WEAPON_TYPE weaponType)
{
	ArmorEfficiency eff;

	switch(armorType)
	{
	case PLATE:
		eff.againstClub = 0.8;
		eff.againstSpear = 1;
		eff.againstSword = 1.2;
		break;
	case CHAINMAIL:
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

	switch (weaponType)
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

int Calculator::randomNumber()
{
	// <random> headeristä tämmönen generaattori
	default_random_engine randGen;
	randGen.seed(time(NULL));

	//Max ja min arvo random luvulle
	uniform_int_distribution<int> distribution(0, 100);

	int randomNumber =  distribution(randGen);

	return randomNumber;
}