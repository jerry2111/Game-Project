#include "GameOver.h"

GameOver::GameOver()
{
	if (!this->font.loadFromFile("font/TA16BIT-Regular.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	float width = 800;
	float height = 600;



	menuGameOver[0].setFont(font);
	menuGameOver[0].setFillColor(sf::Color::Red);
	menuGameOver[0].setString("Play Again");
	menuGameOver[0].setOrigin(menuGameOver[0].getLocalBounds().width / 2, menuGameOver[0].getLocalBounds().height / 2);
	menuGameOver[0].setPosition(sf::Vector2f(width / 2, height / (5) * 3));

	menuGameOver[1].setFont(font);
	menuGameOver[1].setFillColor(sf::Color::White);
	menuGameOver[1].setString("Menu");
	menuGameOver[1].setOrigin(menuGameOver[1].getLocalBounds().width / 2, menuGameOver[1].getLocalBounds().height / 2);
	menuGameOver[1].setPosition(sf::Vector2f(width / 2, height / (5) * 4));

	
}

GameOver::~GameOver()
{

}

void GameOver::draw(sf::RenderWindow& window)
{
	window.draw(gameover);
	for (int i = 0; i < MAX_ITEM; i++)
	{
		
		window.draw(menuGameOver[i]);
	}
}

void GameOver::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menuGameOver[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menuGameOver[selectedItem].setFillColor(sf::Color::Red);
	}
}

void GameOver::MoveDown()
{
	if (selectedItem + 1 < MAX_ITEM)
	{
		menuGameOver[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		menuGameOver[selectedItem].setFillColor(sf::Color::Red);
	}
}
void GameOver::getpoint(int point)
{
	
	std::stringstream ss;
	ss << "Point  " << point;
	this->point.setString(ss.str());
}
//menuGameOver