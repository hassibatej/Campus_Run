#include "floor.h"
#include "stdafx.h"


Floor::Floor() // initialise a Floor
{
}

Floor::~Floor()
{
}

bool Floor::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0, 5000, 20));
    return true;
}

Floor::Floor(std::string textureName, float x, float y) {
    if (!setUpSprite(textureName)) {
    return ;
    }
    position = sf::Vector2f(x,y);
    sprite.setPosition(position);
}
