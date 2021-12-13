#include "stdafx.h"
#include "Tile.h"

Tile::Tile() // initialise a Tile
{
}

Tile::~Tile()
{
}

Tile::Tile(std::string textureName, float x, float y, bool passable, bool exit) {
    if (!setUpSprite(textureName)) {
    return;
    }
    position = sf::Vector2f(x,y);
    sprite.setPosition(position);
    isPassable = passable;
    isExit = exit;
}

bool Tile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,100,20));
    return true;
}







// cat code
/*
Tile::Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging)
	: damaging(damaging)
{
	this->sprite.setTexture(texture_sheet);
	this->sprite.setTextureRect(texture_rect);
}

const sf::FloatRect Tile::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
*/
