#include"stdafx.h"
#include "game.h"
#include "Tile.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();

        game.render();

    }

    //Collision
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close| sf::Style::Resize);
    //Player player(textureSheet, sf::Vector2u(3, 9), 0.3f, 100.0f);
    Tile tile(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
    Tile tile2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));

    //create two tiles
    /*tile.GetCollision().CheckCollision(player.GetCollision(), 0.5f);
    tile2.GetCollision().CheckCollision(player.GetCollision(), 0.5f); */


    /*tile.Draw(window);
    tile2.Draw(window);*/

    //End of application
    return 0;
}


