#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class Item
{
private:

	sf::Sprite item;
	sf::Texture itemTexture[2];


	
	float speed;
	int type;

	void initTexture();

	void initVariable();

	void initSprite();
public:
	Item(float pos_x, float pos_y);
	virtual ~Item();

	//Accessor
	const sf::FloatRect getBounds() const;
	const int& gettype() const;


	//Function
	void update();
	void render(sf::RenderTarget* target);
};
#endif // !ITEM_H

