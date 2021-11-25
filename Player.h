#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<iostream>
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	float attackCooldown;
	float attackCooldownMax;

	int hp;
	int hpMax;

	


	//Private function
	void initVeriables();
	void initTexture();
	void initSprite();


public:
	Player();
	virtual ~Player();
	
	//Accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;


	//Modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);
	void upspeed(const int upspeed);

	//funtion
	void move(const float dirx, const float diry);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
	
};

