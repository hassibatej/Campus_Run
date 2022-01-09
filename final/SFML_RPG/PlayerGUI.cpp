#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont()
{
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
}



void PlayerGUI::initPlayerTabs(sf::VideoMode &vm, sf::Font &font, Player &player)
{
	this->playerTabs = new PlayerGUITabs(vm, font, player);
}

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm)
	: vm(vm)
{
	this->player = player;

	this->initFont();
	this->initPlayerTabs(vm, font, *player);
}

PlayerGUI::~PlayerGUI()
{
	delete this->playerTabs;
}

const bool PlayerGUI::getTabsOpen() const
{
	return this->playerTabs->tabsOpen();
}

void PlayerGUI::toggleCharacterTab()
{
	this->playerTabs->toggleTab(PLAYER_TABS::CHARACTER_TAB);
}

//Functions


void PlayerGUI::updatePlayerTabs()
{
	this->playerTabs->update();
}

void PlayerGUI::update(const float & dt)
{
	this->updatePlayerTabs();
}


void PlayerGUI::renderPlayerTabs(sf::RenderTarget& target)
{
	this->playerTabs->render(target);
}

void PlayerGUI::render(sf::RenderTarget & target)
{
	this->renderPlayerTabs(target);
}
