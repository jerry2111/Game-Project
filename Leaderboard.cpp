#include "Leaderboard.h"

Leaderboard::Leaderboard()
{
	if (!this->font.loadFromFile("font/TA16BIT-Regular.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	float width = 800;
	float height = 600;

}

Leaderboard::~Leaderboard()
{
}

void Leaderboard::draw(sf::RenderWindow& window)
{
}


