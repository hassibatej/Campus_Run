#include "stdafx.h"
#include "obstacles.h"

Obstacles::Obstacles() // initialise obstacles
{
}

Obstacles::~Obstacles()
{
}

Obstacles::Obstacles(std::string textureName, float x, float y, bool deadly, bool slows) { //sprite, positions and features
    if (!setUpSprite(textureName)) {
    return;
    }
    position = sf::Vector2f(x,y);
    sprite.setPosition(position);
    isdeadly = deadly;
    slowsyoudown = slows;
}

bool Obstacles::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        std::cout << "ERROR::PLAYER::Could not load the player sheet!" << "\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,20,20));
    return true;
}
