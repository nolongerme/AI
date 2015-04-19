#pragma once

#include "BodyPart.h"
#include "Weapon.h"
#include "FightSkill.h"

class Character
{
public:
	Character();
	~Character();

	float health;
	float strength, dexterity;
	BodyPart* head, *torso, *rightArm , *leftArm, *rightLeg, *leftLeg;
	Weapon* weapon;
	FightSkill* fightSkill;
	bool isAlive;

};

