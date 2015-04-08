#include "Character.h"


Character::Character()
{

}


Character::~Character()
{
	delete head, torso, leftArm, rightArm, leftLeg, rightLeg, personality, fightStyle, weapon;
}
