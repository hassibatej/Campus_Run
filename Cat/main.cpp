#include"stdafx.h"
#include "game.h"


int main()
{
    srand(static_cast<unsigned>(time(0)));
    Player player.move(4.0f, 0.0f);
    Game game;

    while (game.getWindow().isOpen())
    {
        game.update();

        game.render();

    }

    //End of application
    return 0;
}


