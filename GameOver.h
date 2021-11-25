#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<sstream>
#define MAX_ITEM 2
class GameOver
{
public:
	GameOver();
	~GameOver();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void getpoint(int point);
	int GetPressedItem() { return selectedItem; }

private:




	int selectedItem = 0;
	sf::Font font;
	sf::Text menuGameOver[MAX_ITEM];

	sf::Text gameover;
	sf::Text point;
};

