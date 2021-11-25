#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game No Name Space", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initmusic()
{
	music.setVolume(50.f);
	music.openFromFile("sound/ImpactBig8Bit-GFX030903.ogg");

	
}

void Game::initslideBG()
{
	this->world = new Background(100);
}

void Game::initMenu()
{
	this->menu = new Menu();
	this->gameover = new GameOver();

	
}

void Game::initTectures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Texture/beams (2).png");
}

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("font/TA16BIT-Regular.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text
	this->pointText.setPosition(670.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(16);
	this->pointText.setOrigin(0.f, 0.f);
	this->pointText.setFillColor(sf::Color::White);
	this->pointText.setString("test");

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("Game Over!!!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this ->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	this->Name.setFont(this->font);
	this->Name.setCharacterSize(12);
	this->Name.setPosition(10.f, 10.f);
	this->Name.setString("64010211 NAPAT YORDSAWAD");
	this->Name.setFillColor(sf::Color::White);
	//InitPlayerGUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
	this->playerHpBarBack.setPosition(sf::Vector2f(20.f, 20.f));
}

void Game::initBackground()
{
	if (!this->background.loadFromFile("Texture/space.jpg"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUNG TEXTTURE" << "\n";
	}
	this->worldBackground.setTexture(this->background);
	
	if (!this->Menubackground.loadFromFile("Texture/Menu.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD Menu TEXTTURE" << "\n";
	}
	this->MenuBackground.setTexture(this->Menubackground);
	
	if (!this->Overbackground.loadFromFile("Texture/gameover.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD gameover TEXTTURE" << "\n";
	}
	this->OverBackground.setTexture(this->Overbackground);

	if (!this->Namebackground.loadFromFile("Texture/name.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD Name TEXTTURE" << "\n";
	}
	this->NameBackground.setTexture(this->Namebackground);

	if (!this->Leaderbackground.loadFromFile("Texture/leaderboard.png"))
	{
		std::cout << "ERROR::GAME::COULD NOT LOAD Leaderboard TEXTTURE" << "\n";
	}
	this->LeaderBackground.setTexture(this->Leaderbackground);



	
}

void Game::initSystem()
{
	this->points = 0;
	this->count = 0;
	this->saveRead();
	this->sortscore();
	
}

void Game::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(this->window->getSize().x / 2.f - (this->player->getBounds().width / 2.f), 500.f);
	
}
void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = this->spawnTimerMax;
	this->enemies.clear();
	this->bullets.clear();
}

void Game::initItem()
{
	this->item.clear();
}

void Game::initLeaderBored()
{
	float width = 800;
	float height = 600;
	for (int i = 0; i < 5; i++)
	{
		std::stringstream ssname;
		ssname << data[i].name;
		rankname[i].setFont(font);
		rankname[i].setCharacterSize(20);
		rankname[i].setFillColor(sf::Color::White);
		rankname[i].setString(ssname.str());
		rankname[i].setPosition(sf::Vector2f(200.f, height / (9) * (i+3)));

		std::stringstream ssscore;
		ssscore << data[i].score;
		rankscore[i].setFont(font);
		rankscore[i].setCharacterSize(20);
		rankscore[i].setFillColor(sf::Color::White);
		rankscore[i].setString(ssscore.str());
		rankscore[i].setPosition(sf::Vector2f(450.f, height / (9) * (i + 3)));


	}
}

void Game::initName()
{
	this->namebox = new Textbox();
}

//Con/Des
Game::Game()
{
	
	this->initWindow();
	this->initmusic();
	this->initName();
	this->initslideBG();
	this->initMenu();
	this->initTectures();
	this->initGUI();
	this->initBackground();
	this->initSystem();
	this->initPlayer();
	this->initEnemies();
	this->initLeaderBored();
	
	
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//Delete texture
	for (auto& i : this->textures)
	{
		delete i.second;
	}
	//Delete bullets
	for (auto* i : this->bullets)
	{
		delete i;
	}
	//Delete enemies
	for (auto* i : this->enemies)
	{
		delete i;
	}

}

void Game::run()
{
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	while (this->window->isOpen())
	{
		this->deltatime = clock.restart().asSeconds();

		this->renderWorld();
		if (this->state == 0)
		{
			
			statemenu();
		}
		else if (this->state == 1)
		{
			
			stategame();
		}
		else if (this->state == 2)
		{
			stategameover();
		}
		else if (this->state == 3)
		{
			stateLeaderboard();
		}
		else if (this->state == 4)
		{
			stateName();
		}

	}
	

}

void Game::updatePollEvents()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		
		
		if (this->state == 0)
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
				case sf::Keyboard::Up:
					this->menu->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->menu->MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (this->menu->GetPressedItem())
					{
					case 0:
						std::cout << "Play has been pressed " << "\n";
						this->state = 4;
						break;
					case 1:
						std::cout << "Leaderborad has been pressed " << "\n";
						state = 3;
						break;
					case 2:
						this->window->close();
						break;
					}
					break;
				}
				break;
			}
		}
		else if(this->state == 1)
		{
			if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			{
				this->state = 0;
				initName();
			}
		}
		else if (this->state == 2)
		{
			switch (e.type)
			{
			case sf::Event::KeyReleased:
				switch (e.key.code)
				{
				case sf::Keyboard::Up:
					this->gameover->MoveUp();
					break;
				case sf::Keyboard::Down:
					this->gameover->MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (this->gameover->GetPressedItem())
					{
					case 0:
						std::cout << "Play Again has been pressed " << "\n";
						this->state = 1;
						initPlayer();
						initSystem();
						initEnemies();
						initItem();
						initGUI();
						this->deltatimeupdate = this->clockupdate.restart().asSeconds();
						this->deltatimeitem = this->clockitem.restart().asSeconds();
						break;
					case 1:
						this->state = 0;
						this->initLeaderBored();
						this->initName();
						break;
					
					}
					break;
				}
				break;
			}
		}
		else if (this->state == 3)
		{
			if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			{
				this->state = 0;
				this->initName();
			}
		}
		else if (this->state == 4)
		{
			switch (e.type)
			{
			case sf::Event::TextEntered:
				this->namebox->typedOn(e);
				break;
			}
			if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Enter)
			{
				this->state = 1;
				initPlayer();
				initSystem();
				initEnemies();
				initItem();
				initGUI();
				this->deltatimeupdate = this->clockupdate.restart().asSeconds();
				this->deltatimeitem = this->clockitem.restart().asSeconds();
				
			}
			if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			{
				this->state = 0;
				initSystem();
				this->initName();
			}
		}

		if (e.Event::type == sf::Event::Closed)
			this->window->close();
	
	}
}

void Game::updateMenu()
{

	
}

void Game::updateInput(float dt)
{
	//Move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f*dt*multiple, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f * dt * multiple, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f * dt * multiple);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f * dt * multiple);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&this->player->canAttack())
	{
		music.setVolume(30.f);
		music.openFromFile("sound/ImpactBig8Bit-GFX030903.ogg");
		music.play();
		this->bullets.push_back
		(
		new Bullet(this->textures["BULLET"],
		this->player->getPos().x + this->player->getBounds().width / 2.4f,
		this->player->getPos().y,
		0.f,
		-1.f,
		5.f)
		);
	}

	
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "SCORE  " << this->points;
	this->pointText.setString(ss.str());

	//Upate player GUI
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));
}

void Game::updateWorld()
{
	world->update(this->deltatime);
}

void Game::updateCollision()
{

	//left world collision
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//right world collision
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width,this->player->getBounds().top);
	}
	//top world collision
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left,0.f);
	}
	//Bottom world collision
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
	}
	
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();
		//bullet culling (top of screen)
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);

		}
		++counter;
	}
}


void Game::updateEnemies()
{
	//spawning
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % (this->window->getSize().x - 80) + 10.f , -100.f));
		this->spawnTimer = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		
		if (enemy->getSpeed() == 2.f) { enemy->upspeed(this->count); }
		enemy->update(this->deltatime);
		//bullet culling (top of screen)
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
		}
		//enemy player collision
		else if (enemy->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			Hit.setVolume(50.f);
			Hit.openFromFile("sound/Hit.ogg");
			Hit.play();

		}
		

			
		
	

		++counter;
		
	}

	
	
}

void Game::updateItem()
{
	if (this->deltatimeitem == 10.f / 1.f)
	{
		this->item.push_back(new Item(rand() % (this->window->getSize().x - 80) + 10.f, -100.f));
	}
	unsigned counter = 0;
	for (auto* Item : this->item)
	{
		Item->update();
		if (Item->getBounds().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->item.at(counter);
			this->item.erase(this->item.begin() + counter);

		}
		//enemy player collision
		else if (Item->getBounds().intersects(this->player->getBounds()))
		{
			if (this->item.at(counter)->gettype() == 0)
			{
				this->player->upspeed(1);
			}
			else
			{
				this->count -= 3;
			}
	
			delete this->item.at(counter);
			this->item.erase(this->item.begin() + counter);
			Sitem.setVolume(40.f);
			Sitem.openFromFile("sound/PICK ITEM.wav");
			Sitem.play();

		}
		++counter;
	}
	

	
	
	
}

void Game::updateCombat()
{
	for (int i = 0; i < this->enemies.size(); ++i)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++)
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);
				
				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				

				enemy_deleted = true ;
			}
		}
	}
}

void Game::update()
{
	this->updateWorld();
	this->updateInput(this->deltatime);
	this->player->update();
	this->updateCollision();
	this->updateBullets();
	this->updateEnemies();
	this->updateItem();
	this->updateCombat();
	this->updateGUI();
	

}

void Game::renderMenu()
{
	this->window->clear();
	this->window->draw(this->MenuBackground);
	this->window->draw(this->Name);
	this->menu->draw(*this->window);
	this->window->display();
}

void Game::renderName()
{
	this->window->clear();
	this->window->draw(this->NameBackground);
	this->namebox->Draw(*this->window);
	this->window->display();
}

void Game::renderGameOver()
{
	this->window->clear();
	this->window->draw(this->OverBackground);
	if (state == 2)
	{
		this->pointText.setCharacterSize(40);
		this->pointText.setFillColor(sf::Color::Cyan);
		this->pointText.setOrigin(this->pointText.getLocalBounds().width / 2, this->pointText.getLocalBounds().height / 2);
		this->pointText.setPosition(sf::Vector2f(800 / 2, 600 / (5) * 2));
		this->window->draw(this->pointText);
	}
	this->gameover->draw(*this->window);
	this->window->display();
}

void Game::renderLeaderboard()
{
	this->window->clear();
	this->window->draw(this->LeaderBackground);
	for (int i = 0; i < 5; i++)
	{
		this->window->draw(this->rankname[i]);
		this->window->draw(this->rankscore[i]);

	}
	this->window->display();
}



void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack);
	this->window->draw(this->playerHpBar);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::renderSlide()
{
	world->Draw(*this->window);
}


void Game::rendergame()
{
	this->window->clear();

	//Draw world
	this->renderSlide();

	//Draw all the stuffs
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}


	for (auto* Item : this->item)
	{
		Item->render(this->window);
	}
	


	this->renderGUI();

	//Game Over screen
	if (this->player->getHp() <= 0)
	{
		this->state = 2;
		this->addscore("Score.txt",this->namebox->getText().c_str(), this->points);
	}
		//this->state = 2;
		
		//this->window->draw(this->gameOverText);

	this->window->display();
}

void Game::statemenu()
{
	this->updatePollEvents();
	this->renderMenu();

}

void Game::stategame()
{
	this->deltatimeupdate = this->clockupdate.getElapsedTime().asSeconds();
	this->deltatimeitem = this->clockitem.getElapsedTime().asSeconds();


	if (this->deltatimeupdate > 3.f / 1.f)
	{
		this->deltatimeupdate = 3.f / 1.f;
	}

	if (this->deltatimeupdate == 3.f / 1.f)
	{
		this->count ++;
		this->clockupdate.restart();
	}

	if (this->deltatimeitem > 10.f / 1.f)
	{
		this->deltatimeitem = 10.f / 1.f;
	}


	this->updatePollEvents();
	if (this->player->getHp() > 0)
		this->update();


	this->rendergame();

	if (this->deltatimeitem == 10.f / 1.f)
	{
		this->clockitem.restart();
	}
}

void Game::stategameover()
{
	this->updatePollEvents();
	this->renderGameOver();
	this->renderWorld();
}

void Game::stateLeaderboard()
{
	this->updatePollEvents();
	this->renderLeaderboard();
}

void Game::stateName()
{
	this->updatePollEvents();
	this->renderName();
}

void Game::saveRead()
{
	
	fp = NULL;
	int err = fopen_s(&fp, "Score.txt", "r");
	if (err)
	{
		fopen_s(&fp, "Score.txt", "w");
		return;
	}
	for (int i = 0; i < 5 && !feof(fp) && fp != NULL; i++)
	{
		fscanf_s(fp, "%[^,],", data[i].name, _countof(data[i].name));
		fscanf_s(fp, "%d\n", &data[i].score);
		
	}
	fclose(fp);
}

void Game::sortscore()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (data[j].score > data[i].score)
			{
				ScoreData temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << data[i].name << data[i].score << "\n";
	}
}

void Game::addscore(const char* filename, const char* playername, int score)
{
	FILE* fp = NULL;
	fopen_s(&fp, filename, "w");
	strcpy_s(data[5].name, 19, playername);
	data[5].score = score;
	this->sortscore();
	for (int i = 0; i < 5 && fp != NULL; i++)
	{
		fprintf_s(fp, "%s,%d\n", data[i].name, data[i].score);
	}
	fclose(fp);
}




