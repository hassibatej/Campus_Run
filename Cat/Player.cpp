#include "stdafx.h"
#include "Player.h"
#include <cmath>

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
    if (!this->textureSheet.loadFromFile("./Textures/bullet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0, 0, 10, 10); //SHOULD BE 40 50

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 20.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.0f;
	this->drag = 0.85f;
	this->gravity = 4.f;
	this->velocityMaxY = 15.f;
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}

Player::~Player()
{

}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move(const float dir_x, const float dir_y)
{
    //Acceleration
    this->velocity.x += dir_x * this->acceleration;
    this->velocity.y += 5*dir_y * this->acceleration;



	//Limit velocity
    if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
    if (std::abs(this->velocity.y) > this->velocityMax)
	{
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//Gravity
	this->velocity.y += 1.0 * this->gravity;
    if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleration
	this->velocity *= this->drag;

	//Limit deceleration
    if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
    if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) 
	{
		this->move(0.f, -1.f);
		this->animState = PLAYER_ANIMATION_STATES::JUMPING;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
	{
		this->sprite.move(0.f, 1.f);
	}
}

void Player::updateAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			if (this->getPosition().y >= 400) {
				this->currentFrame.top = 64.f;
				this->currentFrame.left += 64.f;
			}
			else {
				this->currentFrame.top = 0.f;
				this->currentFrame.left = 64.f;
			}
			if (this->currentFrame.left > 192.f)
				this->currentFrame.left = 0;		

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left > 192.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(-3.f, 3.f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 128.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left > 192.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}

		this->sprite.setScale(3.f, 3.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::JUMPING)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.1f || this->getAnimSwitch())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 64.f;
			if (this->currentFrame.left > 128.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else
		this->animationTimer.restart();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->sprite);

	sf::CircleShape circ;
	circ.setFillColor(sf::Color::Red);
	circ.setRadius(2.f);
	circ.setPosition(this->sprite.getPosition());

	target.draw(circ);
}
