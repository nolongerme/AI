#include "Decision.h"


Decision::Decision()
{
}


Decision::~Decision()
{
}

//kertoo DMGn ja osumatarkkuuden kesken‰‰n. N‰in saadaan keskim‰‰r‰inen dmg/lyˆntivuoro
float Decision::averageDmgDealt(BodyPart bodypart, Character character, Character attacker)
{
	float chance = Calculator::probability(bodypart, character.dexterity);
	float  combined = Calculator::damage(*bodypart.armor, *attacker.weapon, attacker.strength);

	float average = chance * combined;
	return average;
}
//Tarkoituksena ottaa keskiarvot, katsoa mik‰ niist‰ tekee keskim‰‰r‰isesti eniten DMGt‰ per vuoro ja palauttaa raaja joka toteuttaa t‰m‰n.
BodyPart Decision::charDecision(Character character, Character attacker, FIGHT_STYLE style)
{
	float head;
	float righta;
	float lefta;
	float rightl;
	float leftl;
	float torso;
	//keskim‰‰r‰set damaget
	switch (style)
	{
		case ADAPTIVE_STYLE:
			head = averageDmgDealt(*character.head, character, attacker);
			righta = averageDmgDealt(*character.rightArm, character, attacker);
			lefta = averageDmgDealt(*character.leftArm, character, attacker);
			rightl = averageDmgDealt(*character.rightLeg, character, attacker);
			leftl = averageDmgDealt(*character.leftLeg, character, attacker);
			torso = averageDmgDealt(*character.torso, character, attacker);
			break;

	//osumatarkkuudet		
		case PASSIVE_STYLE:
			head = Calculator::probability(*character.head, character.dexterity);
			righta = Calculator::probability(*character.rightArm, character.dexterity);
			lefta = Calculator::probability(*character.leftArm, character.dexterity);
			rightl = Calculator::probability(*character.rightLeg, character.dexterity);
			leftl = Calculator::probability(*character.rightArm, character.dexterity);
			torso = Calculator::probability(*character.torso, character.dexterity);
			break;

			//t‰m‰ ei vittu toimi
		//Damaget
		/*case AGRESSIVE_STYLE:
			*head = Calculator::damage(*character.head.armor, *attacker.weapon, attacker.strength);
			*righta = Calculator::damage(*character.rightArm.armor, *attacker.weapon, attacker.strength);
			*lefta = Calculator::damage(*character.leftArm.armor, *attacker.weapon, attacker.strength);
			*rightl = Calculator::damage(*character.rightLeg.armor, *attacker.weapon, attacker.strength);
			*leftl = Calculator::damage(*character.leftLeg.armor, *attacker.weapon, attacker.strength);
			*torso = Calculator::damage(*character.torso.armor, *attacker.weapon, attacker.strength);*/

	}
	//vektori johon n‰m‰ otetaan talteen
	vector<float> bodyPartVector;
	vector<float>::iterator it1;
	vector<float>::iterator it2;

	bodyPartVector.push_back(head);
	bodyPartVector.push_back(righta);
	bodyPartVector.push_back(lefta);
	bodyPartVector.push_back(rightl);
	bodyPartVector.push_back(leftl);
	bodyPartVector.push_back(torso);

	//Asettaa suurimman arvon vectorin ensimm‰iseksi(ehk‰)
	for (it1 = bodyPartVector.begin(); it1 != bodyPartVector.end(); it1++)
	{
		for (it2 = bodyPartVector.begin() + 1; it2 != bodyPartVector.end(); it2++)
		{
			if (*it1 < *it2)
			{
				float temp = *it2;
				*it2 = *it1;
				*it1 = temp;
			}
		}
	}
	//ottaa muistipaikka nollasta arvon ja palauttaa pienimm‰n raajan, mutta eih‰n ne muistipaikat ihan n‰in tainnu menn‰....
	if (bodyPartVector[0] == head)
		return *character.head;
	if (bodyPartVector[0] == lefta)
		return *character.leftArm;
	if (bodyPartVector[0] == righta)
		return *character.rightArm;
	if (bodyPartVector[0] == leftl)
		return *character.leftLeg;
	if (bodyPartVector[0] == rightl)
		return *character.rightLeg;
	if (bodyPartVector[0] == torso)
		return *character.torso;
}