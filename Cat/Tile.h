
#pragma once
#include "stdfx.h"
#include "Collision.h"

class Tile
{
public:
    bool isPassable; //can we move through it or not
    bool isExit; // is it the end if the game
    sf::Vector2f position; // x and y position of player
    sf::Texture texture;
    sf::Sprite sprite;

    //Collision
    Tile(sf::Texture* texture, sf::Vector2f size , sf::Vector2f position);
    Collision GetCollision(){return Collision(body);}
    //void Draw(sf::RenderWindow& window);

    Tile(std::string, float , float , bool, bool);

    bool setUpSprite(std::string);

    Tile();
    ~Tile();

    //extra i'm testin
    float xPos;
    float yPos;
    int topSide;
    int bottomSide;
    int rightSide;
    int leftSide;



private:
    sf::RectangleShape body;
};

