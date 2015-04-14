#pragma once

#include "Character.h"
#include <SFML\Graphics.hpp>

// Varastoi characterin piirrettävät osat
struct RenderCharacter
{
	sf::Sprite armR;
	sf::Sprite armL;
	sf::Sprite legR;
	sf::Sprite legL;
	sf::Sprite head;
	sf::Sprite body;
	sf::Texture charTexture;
};


class Render
{
public:
	Render();
	~Render();
	void addChar(Character& character, sf::Vector2f position);
	void update();
	void updateCharColor(Character& character);

private:
	void draw(RenderCharacter renderChar);

	std::map<Character*, RenderCharacter*> characters;
	sf::RenderWindow _window;
	
};

