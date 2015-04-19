#include "Calculator.h"
#include "Armor.h"
#include "Weapon.h"
#include "Character.h"
#include "Render.h"
#include "Decision.h"
#include <random>
#include <Windows.h>

int main()
{
	
	Character hemmo;
	Character mauno;

	Armor* leatherArmor = new Armor(ARMOR_TYPE::LEATHER, 5);
	Armor* plateArmor = new Armor(ARMOR_TYPE::PLATE, 5);
	Armor* chainArmor = new Armor(ARMOR_TYPE::CHAINMAIL, 5);
	Weapon* sword = new Weapon(WEAPON_TYPE::SWORD, 5);
	Weapon* club = new Weapon(WEAPON_TYPE::CLUB, 6);

	//Mauno
	mauno.dexterity = 7;
	mauno.fightSkill = new FightSkill(PERSONALITY::HONORABLE, FIGHT_STYLE::AGRESSIVE_STYLE);
	mauno.strength = 10;
	mauno.health = 10;
	mauno.isAlive = true;

	mauno.head = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.leftArm = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.leftLeg = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.rightArm = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.rightLeg = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.torso = new BodyPart(BODY_PART_SIZE::LARGE);

	mauno.weapon = sword;
	mauno.head->armor = plateArmor;
	mauno.torso->armor = plateArmor;
	mauno.leftArm->armor = plateArmor;
	mauno.rightArm->armor = plateArmor;
	mauno.leftLeg->armor = plateArmor;
	mauno.rightLeg->armor = plateArmor;


	//Hemmo
	hemmo.dexterity = 7;
	hemmo.fightSkill = new FightSkill(PERSONALITY::HONORABLE, FIGHT_STYLE::PASSIVE_STYLE);
	hemmo.strength = 10;
	hemmo.health = 10;
	hemmo.isAlive = true;

	hemmo.head = new BodyPart(BODY_PART_SIZE::LARGE);
	hemmo.leftArm = new BodyPart(BODY_PART_SIZE::LARGE);
	hemmo.leftLeg = new BodyPart(BODY_PART_SIZE::LARGE);
	hemmo.rightArm = new BodyPart(BODY_PART_SIZE::LARGE);
	hemmo.rightLeg = new BodyPart(BODY_PART_SIZE::LARGE);
	hemmo.torso = new BodyPart(BODY_PART_SIZE::LARGE);

	hemmo.weapon = sword;
	hemmo.head->armor = leatherArmor;
	hemmo.torso->armor = leatherArmor;
	hemmo.leftArm->armor = leatherArmor;
	hemmo.rightArm->armor = leatherArmor;
	hemmo.leftLeg->armor = leatherArmor;
	hemmo.rightLeg->armor = leatherArmor;


	//Renderiin lisätään nämä piirrettävät hahmot
	Render renderer;
	renderer.addChar(mauno, sf::Vector2f(200, 200));
	renderer.addChar(hemmo, sf::Vector2f(600, 200));

	system("pause");

	HitSummary sum;
	Decision decision;

	while(mauno.health > 0 && hemmo.health > 0)
	{	
		
		
		//Mauno lyö
		BodyPart* partToHit = decision.charDecision(hemmo, mauno, mauno.fightSkill->_fightStyle);
		sum = Calculator::hit(mauno, hemmo, *partToHit);
		if(!sum.hitLanded)
			std::cout << "Mauno misses" << std::endl;
		else
			std::cout << "Mauno succesfully hits " << sum.damageDone << std::endl;

		//Piirto
		renderer.update();
		Sleep(1000);

		
		//Hemmo lyö
		partToHit = decision.charDecision(mauno, hemmo, hemmo.fightSkill->_fightStyle);
		sum = Calculator::hit(hemmo, mauno, *partToHit);
		if (!sum.hitLanded)
			std::cout << "Hemmo misses" << std::endl;
		else
			std::cout << "Hemmo succesfully hits " << sum.damageDone << std::endl;

		//Piirto
		renderer.update();	
		Sleep(1000);
	}

	if (mauno.health <= 0)
	{
		std::cout << "**Mauno is dead**" << std::endl;
	}
	else
	{
		std::cout << "**Hemmo is dead**" << std::endl;
	}

	system("pause");
}