
#include "Player.h"

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}


Player::Player()
{
	this->initVariables();
}

Player::~Player()
{

}


const sf::Vector2f Player::getPosition() const
{
}

const sf::FloatRect Player::getGlobalBounds() const
{
}

void Player::setPosition(const float x, const float y)
{
}


void Player::update()
{	
}

void Player::render(sf::RenderTarget & target)
{
}
