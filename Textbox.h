#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
public:
	Textbox();

	void setSelected(bool sel);
	void Draw(sf::RenderWindow& window);
	void typedOn(sf::Event input);
	void Update(sf::Vector2i mousePos);
	void resetString();

	std::string getText() { return text.str(); }
	std::string getName() { return name; }

private:
	sf::Font font;
	sf::Text textbox;
	sf::RectangleShape body;
	std::string name;
	std::ostringstream text;
	sf::Clock delay;
	bool isSelected;
	int limit;

	void inputLogic(int charTyped);
	void deleteLastChar();
};