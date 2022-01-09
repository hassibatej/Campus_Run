#ifndef TILE_H
#define TILE_H


//This file was worked on by Eve 
enum TileTypes { DEFAULT = 0, KILLING = 1, ISFLAG = 2, LEFTWALL = 3}; // Eve and Fiona worked on Tile Types

class Tile
{
private:

protected:
	sf::Sprite shape;
	bool collision;
	short type;

public:
	Tile();
	Tile(short type, int grid_x, int grid_y, float gridSizeF, 
		const sf::Texture& texture, const sf::IntRect& texture_rect,
		const bool collision);
	virtual ~Tile();

	//Accessors
	const short& getType() const;
	virtual const bool & getCollision() const;

	//Functions
	virtual const sf::Vector2f& getPosition() const;
	virtual const sf::FloatRect getGlobalBounds() const;
	virtual const bool intersects(const sf::FloatRect bounds) const;
	virtual const std::string getAsString() const = 0;

	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f player_position = sf::Vector2f()) = 0;
};

#endif