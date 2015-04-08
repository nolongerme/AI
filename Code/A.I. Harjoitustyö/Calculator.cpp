#include "Calculator.h"


Calculator::Calculator()
{
}

float Calculator::probability(BodyPart hitPart, float dexterity)
{
	return BodyPart.chanceToHit*dexterity/10;
}

float Calculator::damage(Armor armor, Weapon weapon)
{
	calcTypeEfficiency(armor.type, weapon.type);
	
}

float Calculator::typeEfficiency(ARMOR_TYPE armorType, SWORD_TYPE swordType)
{

	switch armorType:
	{
	case PLATE:
		

		break;
	case MAIL:
		break;


	}

}



Calculator::~Calculator()
{
}
