#pragma once
#include <iostream>

using namespace std;

enum WEAPON_TYPE { SPEAR, SWORD, CLUB, AXE };



class Weapon
{
public:
	Weapon(WEAPON_TYPE type, float dmg);
	~Weapon();
	float damage;
	WEAPON_TYPE weaponType;

private:


};

