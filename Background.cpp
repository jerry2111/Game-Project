#include "Background.h"

Background::Background(float speed)
{
	this->speed = speed;
	this->size = sf::Vector2f(800.f, 600.f);
	this->texture.loadFromFile("Texture/world2.png");
	body[0].setSize(size);
	body[1].setSize(size);
	body[0].setTexture(&texture);
	body[1].setTexture(&texture);

	

	body[1].setPosition(0.f, body[0].getPosition().y - 596);
}

void Background::update(float deltatime)
{
	for (int i=0;i<2;i++)
	{
		position = body[i].getPosition();

		body[i].move(0, speed * deltatime*2);

		if(body[0].getPosition().y >= 600)
			body[0].setPosition(1, body[1].getPosition().y - 596);
		if (body[1].getPosition().y > 600)
			body[1].setPosition(0, body[0].getPosition().y - 596);
		
	}
}

void Background::Draw(sf::RenderWindow& window)
{
	window.draw(body[0]);
	window.draw(body[1]);
}
