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

	Character mauno;
	Character hemmo;

	mauno.dexterity = 5;
	mauno.fightSkill = new FightSkill(PERSONALITY::HONORABLE,FIGHT_STYLE::AGRESSIVE_STYLE);
	mauno.strength = 10;
	mauno.health = 10;
	mauno.isAlive = true;

	mauno.head = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.leftArm = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.leftLeg = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.rightArm = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.rightLeg = new BodyPart(BODY_PART_SIZE::LARGE);
	mauno.torso = new BodyPart(BODY_PART_SIZE::LARGE);

	Armor *armor = new Armor(ARMOR_TYPE::LEATHER,5);
	Weapon *weapon = new Weapon(WEAPON_TYPE::SWORD,5);

	mauno.weapon = weapon;
	mauno.head->armor = armor;

	/*float damage = Calculator::damage(*armor,weapon,mauno.strength);
	float probability = Calculator::probability(*mauno.head,mauno.dexterity);*/

	//renderiin lisätään nää piirrettävät hahmot
	Render renderer;
	renderer.addChar(mauno, sf::Vector2f(200, 200));
	renderer.addChar(hemmo, sf::Vector2f(600, 200));

	system("pause");

	HitSummary sum;

	while(mauno.health > 0)
	{	
		//Decisionin testi. 100e sille joka arvas oikein että toimiiko se
		//BodyPart test = Decision::charDecision(mauno, mauno, ADAPTIVE_STYLE);
		//sum = Calculator::hit(mauno, mauno,test);
		sum = Calculator::hit(mauno,mauno,*mauno.head);
		
		if(!sum.hitLanded)
			std::cout << "Mauno misses his head" << std::endl;
		else
			std::cout << "Mauno succesfully hits his head for " << sum.damageDone << std::endl;

		//Piirto
		renderer.updateCharColor(mauno); //Joka hahmolle oma updateCharColor
		renderer.update();
		
		Sleep(1000);
	}

	system("pause");
}