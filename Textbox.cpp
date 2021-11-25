#include "Textbox.h"

Textbox::Textbox( )
{
	bool sel = 1;


	if (!this->font.loadFromFile("font/TA16BIT-Regular.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";

	textbox.setFont(font);
	textbox.setPosition(sf::Vector2f{ 310.f,300.f });
	textbox.setFillColor(sf::Color::Black);
	textbox.setCharacterSize(20);


	body.setSize(sf::Vector2f(200.0f, 40.0f));
	//body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(305, 295.f);
	body.setFillColor(sf::Color::White);
	isSelected = sel;
	limit = 10 - 1;
	if (sel)
	{
		textbox.setString("_");
	}
	else
	{
		textbox.setString("  Input your name");
	}
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

void Textbox::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(textbox);
}

void Textbox::typedOn(sf::Event input)
{
	if (isSelected) {
		int charType = input.text.unicode;
		if (charType < 128) {
			if (text.str().length() <= limit) {
				inputLogic(charType);
			}
			else if (text.str().length() > limit && charType == DELETE_KEY) {
				deleteLastChar();
			}
		}
	}
}

void Textbox::Update(sf::Vector2i mousePos)
{

}

void Textbox::resetString()
{
}


void Textbox::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textbox.setString(text.str() + "_");
}

void Textbox::deleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}
