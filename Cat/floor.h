#ifndef FLOOR_H
#define FLOOR_H

#pragma once
#include <stdafx.h>

//this class could have been tiles but was created for efficiency: avoiding a forloop for the creation of the floor

class Floor
{
public:
    Floor();
    sf::Texture texture;
    sf::Sprite sprite;

    Floor(std::string, float , float);
    bool setUpSprite(std::string);
    sf::Vector2f position;
    ~Floor();


};

#endif // FLOOR_H
