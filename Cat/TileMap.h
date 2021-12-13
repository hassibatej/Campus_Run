#pragma once

#include "obstacles.h"
#include"Tile.h"
#include "stdfx.h"
#include <vector>

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
    std::vector< std::vector<Tile*> > tiles; // vector of vectors of Tilepointers
    std::vector< std::vector<Obstacles*> > obstacles;
    int gridLength;

    TileMap();
    ~TileMap();

	void update();
	void render();
};

