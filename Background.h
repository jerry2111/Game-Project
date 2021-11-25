#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class Background
{
public:
	Background(float speed);

	void update(float deltatime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body[2];
	sf::Vector2f position;
	sf::Vector2f size;

	sf::Texture texture;
	float speed ;

};

