#pragma once

#include "obstacles.h"
#include"Tile.h"
#include "stdfx.h"
#include <vector>
#include <list>
#include "floor.h"

class TileMap
{
private:
    sf::Vector2i exitPosition;
    sf::Vector2i playerPosition;
    std::vector<sf::Vector2i> obstaclesPositions; // vector of vectors of the positions of obstacles.

    void setUpObstaclesPositions();
    void setUpTiles();

public:
    void setUpInitialState();
    std::vector < std::vector<Tile*> > tiles; // vector of vectors of Tilepointers
    std::vector < Floor*>  floor;
    std::vector<Obstacles*> bananas;
    int gridLength;

    TileMap();
    ~TileMap();

	void update();
	void render();
};

