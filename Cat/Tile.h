
#pragma once
#include "stdfx.h"


class Tile
{
public:

    bool isPassable; //can we move through it or not
    bool isExit; // is it the end if the game
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;

    Tile(std::string, float , float, bool, bool);
    bool setUpSprite(std::string);

    Tile();
    ~Tile();


};

