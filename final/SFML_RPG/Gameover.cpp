#include "stdafx.h"
#include "Gameover.h"

//Initializer functions
void Gameover::initVariables()
{

}

void Gameover::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void Gameover::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void Gameover::initGui()
{
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	//Background
	this->background.setSize(
		sf::Vector2f
		(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Images_and_Audio/Images/bg4.png"))
	{
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->backgroundTexture);

	//Button background
	this->btnBackground.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 5),
			static_cast<float>(vm.height)
		)
	);

	this->btnBackground.setPosition(gui::p2pX(11.5f, vm), 0.f);
	this->btnBackground.setFillColor(sf::Color(10, 10, 10, 220));

	//Buttons
	this->buttons["GAME_OVER"] = new gui::Button(
		gui::p2pX(40.f, vm), gui::p2pY(20.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Game Over", gui::calcCharSize(vm),
		sf::Color(255, 0, 0, 255), sf::Color(255, 0, 0, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));


	this->buttons["NEW_GAME"] = new gui::Button(
		gui::p2pX(40.f, vm), gui::p2pY(40.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "New Game", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["MENU_STATE"] = new gui::Button(
		gui::p2pX(40.f, vm), gui::p2pY(50.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Main Menu", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EXIT_STATE"] = new gui::Button(
		gui::p2pX(40.f, vm), gui::p2pY(60.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Quit", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void Gameover::resetGui()
{
	/*
	 * Clears the GUI elements and re-initialises the GUI.
	 *
	 * @return void
	 */

	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
	this->buttons.clear();

	this->initGui();
}

Gameover::Gameover(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->resetGui();
}

Gameover::~Gameover()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void Gameover::updateInput(const float& dt)
{

}

void Gameover::updateButtons()
{
	/*Updates all the buttons in the state and handles their functionlaity.*/

	TileMap::recreateInstance();

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosWindow);
	}
	//Text
	if (this->buttons["GAME_OVER"]->isPressed())
	{
		//NOT A BUTTON
	}


	//New Game
	if (this->buttons["NEW_GAME"]->isPressed())
	{
		this->states->push(new GameState(this->stateData));
	}


	//Main Menu
	if (this->buttons["MENU_STATE"]->isPressed())
	{
		//TileMap::recreateInstance();
		this->states->push(new MainMenuState(this->stateData));
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		//TileMap::recreateInstance();
		window->close();
	}
}

void Gameover::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void Gameover::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void Gameover::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	//target->draw(this->btnBackground);

	this->renderButtons(*target);

}
