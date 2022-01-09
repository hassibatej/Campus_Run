#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"
#include "TextState.h"
#include "Gameover.h"
#include"BlackpageState.h"
#include"Won.h"
class Game
{
private:
	//Variables
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	//Initialization
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();

public:
	//Constructors/Destructors
	Game();
	virtual ~Game();

	//Functions
	/*void endDeath(TileMap tileMap);
	void endFlag(TileMap tileMap);*/

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();
};

#endif