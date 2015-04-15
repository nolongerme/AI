#include "Calculator.h"
#include "Armor.h"
#include "Weapon.h"
#include "Character.h"
#include "Render.h"
#include <random>
#include <Windows.h>
#include "Decision.h"

int main()
{

	
	Character hemmo;
	Character mauno;

	mauno.dexterity = 5;
	mauno.fightSkill = new FightSkill(PERSONALITY::HONORABLE,FIGHT_STYLE::AGRESSIVE_STYLE);
	mauno.strength = 10;
	mauno.health = 10;
	mauno.isAlive = true;

	mauno.head = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.leftArm = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.leftLeg = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.rightArm = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.rightLeg = new BodyPart(BODY_PART_SIZE::SMALL);
	mauno.torso = new BodyPart(BODY_PART_SIZE::LARGE);

	Armor *leatherArmor = new Armor(ARMOR_TYPE::LEATHER,5);
	Armor *plateArmor = new Armor(ARMOR_TYPE::PLATE, 5);
	Weapon *weapon = new Weapon(WEAPON_TYPE::SWORD,5);

	mauno.weapon = weapon;
	mauno.head->armor = plateArmor;
	mauno.torso->armor = leatherArmor;
	mauno.leftArm->armor = leatherArmor;
	mauno.rightArm->armor = leatherArmor;
	mauno.leftLeg->armor = leatherArmor;
	mauno.rightLeg->armor = leatherArmor;


	//renderiin lisätään nää piirrettävät hahmot
	Render renderer;
	renderer.addChar(mauno, sf::Vector2f(200, 200));
	renderer.addChar(hemmo, sf::Vector2f(600, 200));

	system("pause");

	HitSummary sum;
	Decision decision;

	while(mauno.health > 0)
	{	
		BodyPart* partToHit = decision.charDecision(mauno, mauno, mauno.fightSkill->_fightStyle);

		sum = Calculator::hit(mauno, mauno, *partToHit);
		
		if(!sum.hitLanded)
			std::cout << "Mauno misses" << std::endl;
		else
			std::cout << "Mauno succesfully hits" << sum.damageDone << std::endl;

		//Piirto
		renderer.updateCharColor(mauno); //Joka hahmolle oma updateCharColor
		renderer.update();
		
		Sleep(1000);
	}

	system("pause");
}