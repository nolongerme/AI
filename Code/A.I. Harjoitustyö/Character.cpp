#include "Character.h"


Character::Character()
{
	head = nullptr, torso = nullptr, leftArm = nullptr, rightArm = nullptr, leftLeg = nullptr, rightLeg = nullptr, weapon = nullptr;
}


Character::~Character()
{
	//delete head, torso, leftArm, rightArm, leftLeg, rightLeg, weapon;
}
