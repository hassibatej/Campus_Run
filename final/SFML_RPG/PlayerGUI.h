#pragma once

#include "PlayerGUITabs.h"

class PlayerGUI
{
private:
	Player* player;

	sf::VideoMode& vm;
	sf::Font font;


	//Player GUI Tabs
	PlayerGUITabs* playerTabs;

	void initFont();

	void initPlayerTabs(sf::VideoMode &vm, sf::Font &font, Player &player);

public:
	PlayerGUI(Player* player, sf::VideoMode& vm);
	virtual ~PlayerGUI();

	//Accessor
	const bool getTabsOpen() const;
	void toggleCharacterTab();

	//Functions

	void updatePlayerTabs();

	void update(const float& dt);

	void renderPlayerTabs(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);
};

