#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#define MAX_ITEM 5
class Leaderboard
{
public:
	Leaderboard();
	~Leaderboard();

	void draw(sf::RenderWindow& window);


private:




	int selectedItem = 0;
	sf::Font font;
	sf::Text rank[MAX_ITEM];
};

