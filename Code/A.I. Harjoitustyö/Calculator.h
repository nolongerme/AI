#pragma once
#include "BodyPart.h"
#include "Armor.h"
#include "Weapon.h"
#include "Character.h"
#include <math.h>
#include <random>
#include <time.h>

struct ArmorEfficiency
{
	float againstSword;
	float againstSpear;
	float againstClub;
};

struct HitSummary
{
	bool hitLanded;
	float damageDone;
};

static class Calculator
{
public:
	Calculator();
	~Calculator();

	/*
		Kun annetaan referenssin‰ nuo charachterit ja bodypartit ym. nii se ei mee turhaan sinne  destructoriin.
		Ei kaadu en‰‰ siihen.
	*/
	
	static float probability(BodyPart& hitPart, float dexterity);
	static float damage(Armor& armor, Weapon& weapon, float strength);
	static HitSummary hit(Character& attacker, Character& target, BodyPart& part);

private:
	static float typeEfficiency(ARMOR_TYPE armorType, WEAPON_TYPE weaponType);
	static float damageValue(float armorValue, float weaponDamage, float strength);
	static float armorEfficiency(ARMOR_TYPE armorType);
	static int randomNumber();
};


