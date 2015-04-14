#include "Decision.h"


Decision::Decision()
{
}


Decision::~Decision()
{
}


float Decision::envittutiia(BodyPart bodypart)
{
	Calculator::probability(bodypart, float dexterity)
	Calculator::damage(*part.armor, *attacker.weapon, attacker.strength);

	float olenpenis = chance * combined;
	return olenpenis;
}

BodyPart Decision::charDecision(BodyPart head, BodyPart rightarm, BodyPart leftarm, BodyPart leftleg, BodyPart rightleg, BodyPart vittutorso)
{
	float _head = envittutiia(head);
	float _righta = envittutiia(leftarm);
	float _lefta = envittutiia(rightarm);
	float _rightl = envittutiia(leftleg);
	float _leftl = envittutiia(rightleg);
	float _torso = envittutiia(vittutorso);

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
			if (pilluperkele->at(i) < pilluperkele->at(j))
			{
				float temp = pilluperkele->at(j);
				pilluperkele->at(j) = pilluperkele->at(i);
				pilluperkele->at(i) = temp;
			}
		}
	}
	if (pilluperkele->at(0) == _head)
		return head;
	if (pilluperkele->at(0) == _lefta)
		return leftarm;
	if (pilluperkele->at(0) == _righta)
		return rightarm;
	if (pilluperkele->at(0) == _leftl)
		return leftleg;
	if (pilluperkele->at(0) == _rightl)
		return rightleg;
	if (pilluperkele->at(0) == _torso)
		return vittutorso;
}