//Rojin Radmehr
//antonina mijatovic worked on this file

#include "stdafx.h"
#include "MainMenuState.h"

//Initializer functions
void MainMenuState::initVariables()
{

}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}


//Marie-Alexis worked on audio in this file
sf::SoundBuffer buffer6;
sf::Sound accept;

void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		buffer6.loadFromFile("Images_and_Audio/Audio/accept.wav");
		accept.setBuffer(buffer6);
		accept.play();
		accept.setVolume(100.f);

		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}


//Marie-Alexis worked on implementing the background in this section
void MainMenuState::initGui()
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

	if (!this->backgroundTexture.loadFromFile("Images_and_Audio/Images/bg2.png"))
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
	this->buttons["GAME_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(30.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "New Game", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0)
	);

	this->buttons["ABOUT"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(50.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "About us", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	this->buttons["EXIT_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(70.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Quit", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

void MainMenuState::resetGui()
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

MainMenuState::MainMenuState(StateData* state_data)
	: State(state_data)
{
	this->initVariables();
	this->initFonts();
	this->initKeybinds();
	this->initGui();
	this->resetGui();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}


void MainMenuState::updateInput(const float& dt)
{

}

void MainMenuState::updateButtons()
{
	/*Updates all the buttons in the state and handles their functionlaity.*/

	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosWindow);
	}

	//New game
	if (this->buttons["GAME_STATE"]->isPressed())
	{
		this->states->push(new GameState(this->stateData));
	}

	//About us
	if (this->buttons["ABOUT"]->isPressed())
	{
		this->states->push(new About(this->stateData));
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		window->close();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	target->draw(this->btnBackground);

	this->renderButtons(*target);

}
