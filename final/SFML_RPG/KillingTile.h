#pragma once
#ifndef KILLINGTILE_H
#define KILLINGTILE_H

#include "Tile.h"

class KillingTile :
	public Tile
{
private:

protected:

public:
	KillingTile(short type, int grid_x, int grid_y, float gridSizeF,
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		bool collision = false);

	virtual ~KillingTile();

	//Functions
	virtual const std::string getAsString() const;

	virtual void update();
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f player_position = sf::Vector2f());
};

#endif //!KILLINGTILE_H
