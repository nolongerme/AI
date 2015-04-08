#pragma once

#include "BodyPart.h"
#include "Weapon.h"
#include "Personality.h"
#include "FightStyle.h"

class Character
{
public:
	Character();
	~Character();

	/*
	 *Char's attributes. Everything is public.
	 */
	float health;
	float strength, dexterity;
	BodyPart* head, torso, rightArm, leftArm, rightLeg, leftLeg;
	Weapon* weapon;
	Personality* personality;
	FightStyle* fightStyle;
	bool isAlive;

};

