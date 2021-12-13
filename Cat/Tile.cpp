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
    return ;
    }
    position = sf::Vector2f(x,y);
    sprite.setPosition(position);
    isPassable = passable;
    isExit = exit;
}

/*int Tile::get_height(){
    return height;
}

int Tile::get_length(){
    return length;
}*/
bool Tile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0, 100, 20));
    return true;
}

