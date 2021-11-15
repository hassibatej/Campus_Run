#pragma once
#include "obstacle.h"
enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::Clock animationTimer;

	//Core

	void initVariables();
	void initTexture();
	void initSprite();

	//bool isCollidingWithCoin(Coin* coin) {
	//	if (this->getGlobalBounds().intersects(coin->getGlobalBounds())) {
	//		return true;
	//	}
	//	return false;
	//}


public:
	Player();
	virtual ~Player();

	//Accessors
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	//Modifiers
	void setPosition(const float x, const float y);

	//Functions	
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);
};

