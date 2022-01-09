#pragma once

#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "GameState.h"
#include "SettingsState.h"
#include"MainMenuState.h"
#include"ComingSoon.h"


class Won :
	public State
{
private:
	//Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	sf::RectangleShape btnBackground;
	std::map<std::string, gui::Button*> buttons;

	//Functions
	void initVariables();
	void initFonts();
	void initKeybinds();
	void initGui();
	void resetGui();


public:
	Won(StateData* state_data);
	virtual ~Won();

	//Functions
	void updateInput(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};



