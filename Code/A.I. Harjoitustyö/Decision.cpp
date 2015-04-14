#include "Decision.h"


Decision::Decision()
{
}


Decision::~Decision()
{
}


float Decision::envittutiia(BodyPart bodypart, Character character, Character attacker)
{
	float chance = Calculator::probability(bodypart, character.dexterity);
	float  combined = Calculator::damage(*bodypart.armor, *attacker.weapon, attacker.strength);

	float olenpenis = chance * combined;
	return olenpenis;
}

BodyPart Decision::charDecision(BodyPart head, BodyPart rightarm, BodyPart leftarm, BodyPart leftleg, BodyPart rightleg, BodyPart vittutorso, Character character, Character attacker)
{
	float _head = envittutiia(head, character, attacker);
	float _righta = envittutiia(leftarm, character, attacker);
	float _lefta = envittutiia(rightarm, character, attacker);
	float _rightl = envittutiia(leftleg, character, attacker);
	float _leftl = envittutiia(rightleg, character, attacker);
	float _torso = envittutiia(vittutorso, character, attacker);

	vector<float> pilluperkele;

	_head = pilluperkele.push_back;
	_righta = pilluperkele.push_back;
	_lefta = pilluperkele.push_back;
	_rightl = pilluperkele.push_back;
	_leftl = pilluperkele.push_back;
	_torso = pilluperkele.push_back;

	for (int i = 0; i < pilluperkele.size; i++)
	{
		for (int j = i + 1; j < pilluperkele.size; j++)
		{
			if (pilluperkele[i] < pilluperkele[i])
			{
				float temp = pilluperkele[j];
				pilluperkele[j] = pilluperkele[i];
				pilluperkele[i] = temp;
			}
		}
	}
	if (pilluperkele[0] == _head)
		return head;
	if (pilluperkele[0] == _lefta)
		return leftarm;
	if (pilluperkele[0] == _righta)
		return rightarm;
	if (pilluperkele[0] == _leftl)
		return leftleg;
	if (pilluperkele[0] == _rightl)
		return rightleg;
	if (pilluperkele[0] == _torso)
		return vittutorso;
}