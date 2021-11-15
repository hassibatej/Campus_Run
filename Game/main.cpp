
#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(0)));

	Game game;

	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}

<<<<<<< HEAD
	//End of application
=======
>>>>>>> main
	return 0;
}