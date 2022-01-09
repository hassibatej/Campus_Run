#pragma once
#ifndef LEFTWALL_H
#define LEFTWALL_H

#include "Tile.h"
// Eve worked on this file
class LeftWall :
	public Tile
{
private:

protected:

public:
	LeftWall(short type, int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		bool collision = false);

	virtual ~LeftWall();

	//Functions
	virtual const std::string getAsString() const;

	virtual void update();
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f player_position = sf::Vector2f());
};

#endif //!LeftWall_H
