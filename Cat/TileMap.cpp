#include "stdafx.h"
#include "TileMap.h"
#include "Tile.h"

TileMap::TileMap() // initialise the map
{
    gridLength = 50;
    setUpInitialState();

}

TileMap::~TileMap()
{
}


void TileMap::update()
{
}

void TileMap::render()
{
}

void TileMap::setUpInitialState() {
    exitPosition = sf::Vector2i(3990,380);
    playerPosition = sf::Vector2i(gridLength -1,300); // tried to edit this to make him start from bottom but doesn't work?
    setUpTiles();
}

void TileMap::setUpObstaclesPositions(){
    obstacles.clear();

    std::vector<Obstacles*> bananas;

    std::vector<int> bananaspositions = {2,3,4,5,6,15,26};
    for ( int i = 0; i < gridLength; i++){
        for(auto & j : bananaspositions)
            if (i == j){
                bananas.push_back(new Obstacles("./Textures/banana.png",j*100,200, true, false));
            }
        }
    obstacles.push_back(bananas);
}
void TileMap::setUpTiles(){
    tiles.clear();
    // creating a matrix of tiles

    std::vector<Tile*> firstRow; // here we construct the floor

    for (int i = 0; i < gridLength; i++ ){
        firstRow.push_back(new Tile("./Textures/floor.png", i*100, 380, false, false));
    }

    tiles.push_back(firstRow);

    std::vector<Tile*> secondRow;


    std::vector<int> platforms = {3,7,12,13,14,15,20,23,24,27,28,34,35,36,39,40,41,45,46,47,48};

    for ( int i = 0; i < gridLength; i++){
        for(auto & j : platforms)
            if (i == j){
                secondRow.push_back(new Tile("./Textures/floor.png",j*100,300, false, false));
            }
        }



    tiles.push_back(secondRow);

}

