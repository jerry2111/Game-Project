#pragma once
#include<stdio.h>
#include<map>
#include <vector>
#include<string>
#include<sstream>
#include<utility>
#include<algorithm>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Background.h"
#include "Item.h"
#include "Menu.h"
#include "GameOver.h"
#include "Textbox.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	//window
	sf::RenderWindow* window;
	int state = 0;
	float multiple = 150.f;
	Background* world;
	//Menu
	Menu* menu;
	GameOver* gameover;

	//NAME
	Textbox* namebox;
	const char* playername;
	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;


	//sound
	sf::Music music;
	sf::Music Hit;
	sf::Music Sitem;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Text gameOverText;
	sf::Text Name;

	//World
	sf::Texture background;
	sf::Sprite worldBackground;
	sf::Texture Menubackground;
	sf::Sprite MenuBackground;
	sf::Texture Leaderbackground;
	sf::Sprite LeaderBackground;
	sf::Texture Overbackground;
	sf::Sprite OverBackground;
	sf::Texture Namebackground;
	sf::Sprite NameBackground;

	std::vector<Background> backgrounds;
	
	
	//TIME
	float deltatimeupdate = 0.f;
	float deltatimeitem = 0.f;
	sf::Clock clockupdate;
	sf::Clock clockitem;
	float count = 0;

	float deltatime = 0.f;
	sf::Clock clock;


	//Sustems
	unsigned points;

	//Player
	Player* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//save score
	FILE* fp;
	struct ScoreData
	{
		char name[20];
		int score;
	}data[6];
	sf::Text rankname[5];
	sf::Text rankscore[5];
	

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	std::vector<Item*> item;

	
	

	//private function
	void initWindow();
	void initmusic();
	void initslideBG();
	void initMenu();
	void initTectures();
	void initGUI();
	void initBackground();
	void initSystem();
	void initPlayer();
	void initEnemies();
	void initItem();
	void initLeaderBored();
	void initName();


public:
	Game();
	virtual ~Game();
	

	
	//function
	void run();

	void updatePollEvents();
	void updateMenu();
	void updateInput(float dt);
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateItem();
	void updateCombat();
	void update();
	void renderMenu();
	void renderName();
	void renderGameOver();
	void renderLeaderboard();
	void renderGUI();
	void renderWorld();
	void renderSlide();
	void rendergame();
	void statemenu();//0
	void stategame();//1
	void stategameover();//2
	void stateLeaderboard();//3
	void stateName();//4
	void saveRead();
	void sortscore();
	void addscore(const char* filename, const char* playername, int score);

};

