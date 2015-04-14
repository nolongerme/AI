#include "Render.h"


Render::Render() : _window(sf::VideoMode(800, 600), "AI window")
{
	
}


Render::~Render()
{
}


void Render::update()
{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				_window.close();
			}
		}

		_window.clear(sf::Color::White);
		
		std::map<Character*, RenderCharacter*>::iterator it;
		for (it = characters.begin(); it != characters.end(); it++)
		{
			draw(*it->second);
		}

		_window.display();
}


void Render::draw(RenderCharacter renderChar)
{
	_window.draw(renderChar.body);
	_window.draw(renderChar.head);
	_window.draw(renderChar.armR);
	_window.draw(renderChar.armL);
	_window.draw(renderChar.legR);
	_window.draw(renderChar.legL);
}


void Render::updateCharColor(Character& character)
{
	//TODO: ruumiin osan hela ei sais mennä alle nollan asd 

	std::map<Character*, RenderCharacter*>::iterator it;
	for (it = characters.begin(); it != characters.end(); it++)
	{
		it->second->body.setColor(sf::Color(character.torso->health * 10, 0, 0, 255));
		it->second->head.setColor(sf::Color(255, character.head->health * 51, character.head->health * 51, 255));
		it->second->armR.setColor(sf::Color(character.rightArm->health * 10, 0, 0, 255));
		it->second->armL.setColor(sf::Color(character.leftArm->health * 10, 0, 0, 255));
		it->second->legR.setColor(sf::Color(character.rightLeg->health * 10, 0, 0, 255));
		it->second->legL.setColor(sf::Color(character.rightLeg->health * 10, 0, 0, 255));
	}
}


void Render::addChar(Character& character, sf::Vector2f position)
{
	RenderCharacter* rendCharacter = new RenderCharacter;

	//Lataa tekstuuri
	rendCharacter->charTexture.loadFromFile("../../assets/texture.png");

	//Tekstuurit
	rendCharacter->armR.setTexture(rendCharacter->charTexture);
	rendCharacter->armL.setTexture(rendCharacter->charTexture);
	rendCharacter->legR.setTexture(rendCharacter->charTexture);
	rendCharacter->legL.setTexture(rendCharacter->charTexture);
	rendCharacter->body.setTexture(rendCharacter->charTexture);
	rendCharacter->head.setTexture(rendCharacter->charTexture);


	//Tekstuuri rectit spriteille
	rendCharacter->armR.setTextureRect(sf::IntRect(0, 0, 32, 64));
	rendCharacter->armL.setTextureRect(sf::IntRect(0, 0, 32, 64)); // Sama tekstuuri kun armR
	rendCharacter->legR.setTextureRect(sf::IntRect(0, 0, 32, 64));
	rendCharacter->legL.setTextureRect(sf::IntRect(0, 0, 32, 64)); // Sama tekstuuri kun legR

	rendCharacter->body.setTextureRect(sf::IntRect(0, 0, 32, 64));
	rendCharacter->head.setTextureRect(sf::IntRect(0, 0, 32, 32));

	//Hemmon paikka. Ruumiin osille paikat bodyn suhteen
	//NÄMÄ SÄÄDÖT PITÄÄ VIELÄ SÄÄDELLÄ! (kova koodi jee) 
	rendCharacter->body.setPosition(position);
	rendCharacter->head.setPosition(position.x, position.y - 50);

	//Kädet
	rendCharacter->armR.setPosition(position.x - 70, position.y);
	rendCharacter->armL.setPosition(position.x + 70, position.y);

	//Jalat
	rendCharacter->legR.setPosition(position.x - 70, position.y + 70);
	rendCharacter->legL.setPosition(position.x + 70, position.y + 70);

	characters.insert(std::make_pair(&character, rendCharacter));
}