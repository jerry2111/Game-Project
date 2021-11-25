#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#define MAX_ITEM 3
class Menu
{
public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItem; }

private:

	


	int selectedItem = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEM];
};

