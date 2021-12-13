#include "stdafx.h"
#include "TileMap.h"
#include "Tile.h"
#include "floor.h"
#include "obstacles.h"

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


void TileMap::setUpTiles(){
    tiles.clear();
    floor.clear();
    bananas.clear();

    std::map<int, int> bananafloorpositions = {{1,7},{2,10}, {3,16}, {4,20}, {5, 27}, {6,33}, {7,39}};//23,24,27,28,34,35,36,39,40,41,45,46,47,48};
    std::map<int, int> bananaplatformpositions = {{1,5},{2,16}, {3,29}, {4,30}, {5,42}, {6,23}};//23,24,27,28,34,35,36,39,40,41,45,46,47,48};

    for ( int i = 1; i <8 ; i++){
                bananas.push_back(new Obstacles("./Textures/banana.png",bananafloorpositions[i]*100,280, true, false));
            }
    for ( int i = 1; i <7 ; i++){
                bananas.push_back(new Obstacles("./Textures/banana.png",bananaplatformpositions[i]*100,360, true, false));
            }

    // here we construct the floor

    floor.push_back(new Floor("./Textures/floor.png",0,380));

    /*std::vector<Tile*> vector1;
    for ( int i = 0; i <gridLength ; i++){
        vector1.push_back(new Tile("./Textures/floor.png", i * 100, 380, false, false));
    }

    tiles.push_back(vector1);*/

    std::vector<Tile*> secondRow;


    std::map<int, int> platforms = {{1,7},{2,8},{3,10}, {4,11}, {5,16}, {6,20}, {7,21}, {9,22}, {10, 25}, {11, 27}, {12,33}, {13,34}, {14,37}, {15,39}};//23,24,27,28,34,35,36,39,40,41,45,46,47,48};

    for ( int i = 1; i <16 ; i++){
                secondRow.push_back(new Tile("./Textures/floor.png",platforms[i]*100,300, false, false));
            }

    tiles.push_back(secondRow);

}



