#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <SFML/Graphics.hpp>

class Obstacles
{
public:
    Obstacles();
    ~Obstacles();

    bool isdeadly;
    bool slowsyoudown; // lets concentrate on this once the isdeadly part works
    sf::Vector2f position; // x and y podition of player
    sf::Texture texture;
    sf::Sprite sprite;

    Obstacles(std::string, float , float , bool, bool);
    bool setUpSprite(std::string);

};

#endif // OBSTACLES_H

