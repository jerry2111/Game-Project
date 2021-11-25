#include "Enemy.h"
#include "Game.h"
#include<iostream>

void Enemy::initTextureEN()
{
	this->textureEN[0].loadFromFile("Texture/enemy.png");
	this->textureEN[1].loadFromFile("Texture/enemy_2_-removebg-preview.png");
}

void Enemy::initVariable()
{
	this->scale = rand() % 5 + 3;
	this->type   = rand() % 2;
	this->speed	 = 2.f ;
	this->hpMax  = 10;
	this->hp     = this->hpMax;
	this->damage = (this->type + 1) * (this->scale);
	this->points = 2 * (this->type + 1) * (this->scale);
}

void Enemy::initSpriteEN()
{
	this->spriteEN.setTexture(this->textureEN[this->type]);
	std::cout << this->type << "\n";
	this->spriteEN.scale((this->scale) * 0.06f, (this->scale) * 0.06f);
}

Enemy::Enemy(float pos_x,float pos_y)
{
	this->initTextureEN();
	this->initVariable();	
	this->initSpriteEN();
	this->spriteEN.setPosition(pos_x, pos_y);
	
}

Enemy::~Enemy()
{
}

//Accessors
const sf::FloatRect Enemy::getBounds() const
{
	return this->spriteEN.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getSpeed() const
{
	return this->speed;
}

void Enemy::upspeed(float count)
{
	this->speed += (count)*0.1f;
}

//Functions
void Enemy::update(float dt)
{
	this->spriteEN.move(0.f, this->speed*150*dt);

}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->spriteEN);
}


