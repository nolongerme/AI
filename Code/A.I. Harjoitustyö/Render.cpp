#include "Render.h"


Render::Render() : _window(sf::VideoMode(800, 600), "AI window")
{
	_window.setPosition(sf::Vector2i(1000, 200));
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

	std::map<Character*, RenderCharacter*>::iterator it;
	it = characters.find(&character);

	int r = 255;
	int g = 255;
	int b = 255;
	int a = 255;

	it->second->body.setColor(sf::Color(r, g * character.torso->health,		b * character.torso->health,	a));
	it->second->head.setColor(sf::Color(r, g * character.head->health,		b * character.head->health,		a));
	it->second->armR.setColor(sf::Color(r, g * character.rightArm->health,	b * character.rightArm->health, a));
	it->second->armL.setColor(sf::Color(r, g * character.leftArm->health,	b * character.leftArm->health,	a));
	it->second->legR.setColor(sf::Color(r, g * character.rightLeg->health,	b * character.rightLeg->health, a));
	it->second->legL.setColor(sf::Color(r, g * character.leftLeg->health,	b * character.leftLeg->health,	a));
}


void Render::addChar(Character& character, sf::Vector2f position)
{
	RenderCharacter* rendCharacter = new RenderCharacter;

	//Lataa tekstuuri
	rendCharacter->charTexture.loadFromFile("../../assets/character.png");

	//Tekstuurit
	rendCharacter->armR.setTexture(rendCharacter->charTexture);
	rendCharacter->armL.setTexture(rendCharacter->charTexture);
	rendCharacter->legR.setTexture(rendCharacter->charTexture);
	rendCharacter->legL.setTexture(rendCharacter->charTexture);
	rendCharacter->body.setTexture(rendCharacter->charTexture);
	rendCharacter->head.setTexture(rendCharacter->charTexture);


	//Tekstuuri rectit spriteille
	int spriteWidth = 32;

	rendCharacter->head.setTextureRect(sf::IntRect(0, 0, 32, 32));				
	rendCharacter->armR.setTextureRect(sf::IntRect(spriteWidth, 0, 32, 64));	
	rendCharacter->body.setTextureRect(sf::IntRect(spriteWidth * 2, 0, 32, 64));
	rendCharacter->armL.setTextureRect(sf::IntRect(spriteWidth * 3, 0, 32, 64));
	rendCharacter->legL.setTextureRect(sf::IntRect(spriteWidth * 4, 0, 32, 64)); 
	rendCharacter->legR.setTextureRect(sf::IntRect(spriteWidth * 5, 0, 32, 64));


	//Hemmon paikka. Ruumiin osille paikat bodyn suhteen
	rendCharacter->body.setPosition(position);
	rendCharacter->head.setPosition(position.x, position.y - rendCharacter->head.getGlobalBounds().height);
	//K‰det
	rendCharacter->armR.setPosition(position.x - rendCharacter->body.getGlobalBounds().width, position.y);
	rendCharacter->armL.setPosition(position.x + rendCharacter->armL.getGlobalBounds().width, position.y);
	//Jalat
	rendCharacter->legR.setPosition(position.x + rendCharacter->body.getGlobalBounds().width * 0.5, 
		position.y + rendCharacter->body.getGlobalBounds().height);

	rendCharacter->legL.setPosition(position.x - rendCharacter->body.getGlobalBounds().width * 0.5, 
		position.y + rendCharacter->body.getGlobalBounds().height);

	//Lis‰‰ hemmot mappiin
	characters.insert(std::make_pair(&character, rendCharacter));
}