#include "Weapon.h"


Weapon::Weapon(WEAPON_TYPE type, float dmg)
{
	if (dmg > 10)
		dmg = 10;
	if (dmg < 1)
		dmg = 1;
	type = weaponType;
	dmg = damage;
}


Weapon::~Weapon()
{
}

