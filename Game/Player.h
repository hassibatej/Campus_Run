#pragma once
#include "obstacle.h"
enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Player
{
private:

	void initVariables();

public:
	Player();
	virtual ~Player();

	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	void setPosition(const float x, const float y);

	void update();
	void render(sf::RenderTarget& target);
};

