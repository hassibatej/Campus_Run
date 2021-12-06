#include"stdafx.h"
#include "game.h"
#include "TileMap.h"
#include "Tile.h"

void Game::initWindow()
{
    this->window.create(sf::VideoMode(4000, 400), "Campus Run!", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);

}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height
		);
	}
}

void Game::update()
{
	//Polling window events
	while (this->window.pollEvent(this->ev))
	{
        if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();

		if (
			this->ev.type == sf::Event::KeyReleased &&
			(
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::W ||
				this->ev.key.code == sf::Keyboard::S
				)
			)
		{
			this->player->resetAnimationTimer();
		}
	}

	this->updatePlayer();

	this->updateCollision();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderTileMap(){
    TileMap().setUpInitialState();

    for (int i = 0; i < 2; i++ ){
        for (int j = 0; j < TileMap().tiles[i].size(); j++){
            this -> window.draw(TileMap().tiles[i][j]->sprite);
        }
     }
    for (int i = 0; i < TileMap().obstacles.size(); i++ ){
        for (int j = 0; j < TileMap().obstacles[i].size(); j++){
            this -> window.draw(TileMap().obstacles[i][j]->sprite);
        }
     }
}

void Game::render()
{
	this->window.clear();

	//Render game
	this->renderPlayer();
    this->renderTileMap();


	this->window.display();
}



const sf::RenderWindow & Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
