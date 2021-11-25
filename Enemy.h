#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy
{
private:
	sf::Sprite spriteEN;
	sf::Texture textureEN[2];


	sf::Sprite item;
	sf::Texture itemTexture;


	int scale;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initTextureEN();
	
	void initVariable();

	void initSpriteEN();
public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Accessor
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;
	const int& getSpeed() const;

	//updatevalue
	void upspeed(float deltatime);

	//Function
	void update(float dt);
	void render(sf::RenderTarget* target);
};

#endif // !ENEMY_H
