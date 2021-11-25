#include "Item.h"

void Item::initTexture()
{
	this->itemTexture[0].loadFromFile("Texture/potion1.png");
	this->itemTexture[1].loadFromFile("Texture/potion2.png");
}

void Item::initVariable()
{
	this->speed = 2.f;
	this->type = rand() % 2;
}

void Item::initSprite()
{
	this->item.setTexture(this->itemTexture[this->type]);
	this->item.setScale(0.1f, 0.1f);
	//std::cout << this->type << "\n";
}

Item::Item(float pos_x, float pos_y)
{
	this->initTexture();
	this->initVariable();
	this->initSprite();
	this->item.setPosition(pos_x, pos_y);
}

Item::~Item()
{

}

const sf::FloatRect Item::getBounds() const
{
	return this->item.getGlobalBounds();
}

const int& Item::gettype() const
{
	return this->type;
}

void Item::update()
{
	this->item.move(0.f, this->speed);
}

void Item::render(sf::RenderTarget* target)
{
	target->draw(this->item);
}
