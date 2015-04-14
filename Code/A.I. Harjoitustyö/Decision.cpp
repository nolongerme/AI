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
//t‰m‰ on kuraa eik‰ k‰‰nny koska olen mestari. Tarkoituksena ottaa keskiarvot, katsoa mik‰ niist‰ tekee keskim‰‰r‰isesti eniten DMGt‰ per vuoro ja palauttaa raaja joka toteuttaa t‰m‰n.
BodyPart Decision::charDecision(BodyPart head, BodyPart rightarm, BodyPart leftarm, BodyPart leftleg, BodyPart rightleg, BodyPart torso, Character character, Character attacker)
{
	//keskim‰‰r‰set damaget
	float _head = averageDmgDealt(head, character, attacker);
	float _righta = averageDmgDealt(leftarm, character, attacker);
	float _lefta = averageDmgDealt(rightarm, character, attacker);
	float _rightl = averageDmgDealt(leftleg, character, attacker);
	float _leftl = averageDmgDealt(rightleg, character, attacker);
	float _torso = averageDmgDealt(torso, character, attacker);

	//vektori johon n‰m‰ otetaan talteen
	vector<float> bodyPartVector;

	bodyPartVector.push_back(_head);
	bodyPartVector.push_back(_righta);
	bodyPartVector.push_back(_lefta);
	bodyPartVector.push_back(_rightl);
	bodyPartVector.push_back(_leftl);
	bodyPartVector.push_back(_torso);

	//Asettaa suurimman arvon vectorin ensimm‰iseksi(ehk‰)
	for (int i = 0; i < bodyPartVector.size; i++)
	{
		for (int j = i + 1; j < bodyPartVector.size; j++)
		{
			if (bodyPartVector[i] < bodyPartVector[i])
			{
				float temp = bodyPartVector[j];
				bodyPartVector[j] = bodyPartVector[i];
				bodyPartVector[i] = temp;
			}
		}
	}
	//ottaa muistipaikka nollasta arvon ja palauttaa pienimm‰n raajan, mutta eih‰n ne muistipaikat ihan n‰in tainnu menn‰....
	if (bodyPartVector[0] == _head)
		return head;
	if (bodyPartVector[0] == _lefta)
		return leftarm;
	if (bodyPartVector[0] == _righta)
		return rightarm;
	if (bodyPartVector[0] == _leftl)
		return leftleg;
	if (bodyPartVector[0] == _rightl)
		return rightleg;
	if (bodyPartVector[0] == _torso)
		return torso;
}