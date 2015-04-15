#include "Decision.h"


Decision::Decision()
{
}


Decision::~Decision()
{
}

//kertoo DMGn ja osumatarkkuuden kesken‰‰n. N‰in saadaan keskim‰‰r‰inen dmg/lyˆntivuoro
float Decision::averageDmgDealt(BodyPart bodypart, Character target, Character attacker)
{
	float chance = Calculator::probability(bodypart, target.dexterity);
	float  combined = Calculator::damage(*bodypart.armor, *attacker.weapon, attacker.strength);

	float average = chance * combined;
	return average;
}

//Tarkoituksena ottaa keskiarvot, katsoa mik‰ niist‰ tekee keskim‰‰r‰isesti eniten DMGt‰ per vuoro ja palauttaa raaja joka toteuttaa t‰m‰n.
BodyPart* Decision::charDecision(Character target, Character attacker, FIGHT_STYLE style)
{
	//Otetaan kaikki targetin BodyPartit vektoriin
	_bodyParts.push_back(target.head);
	_bodyParts.push_back(target.torso);
	_bodyParts.push_back(target.leftArm);
	_bodyParts.push_back(target.rightArm);
	_bodyParts.push_back(target.leftLeg);
	_bodyParts.push_back(target.rightLeg);

	std::vector<BodyPart*>::iterator it;

	BodyPart* bodyPartToHit = nullptr;
	float highest = 0.0;

	switch (style)
	{
		case ADAPTIVE_STYLE:
			break;

		//Osumatarkkuuden mukaan		
		case PASSIVE_STYLE:
		
			for (it = _bodyParts.begin(); it != _bodyParts.end(); it++)
			{
				float prob = Calculator::probability(*(*it), attacker.dexterity);
				if ( prob > highest)
				{
					highest = prob;
					bodyPartToHit = *it;
				}
			}	
			break;

		//Vahingon mukaan
		case AGRESSIVE_STYLE:

			for (it = _bodyParts.begin(); it != _bodyParts.end(); it++)
			{
				float dmg = Calculator::damage(*(*it)->armor, *attacker.weapon, attacker.strength);
				if (dmg > highest && (*it)->health != 0)
				{
					highest = dmg;
					bodyPartToHit = *it;
				}
			}
			break;

		default:
			break;
	}

	return bodyPartToHit;
}