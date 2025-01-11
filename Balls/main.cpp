#include "Game.h"
#include<iostream>
#include<cstdlib>

//Here we only manage the window . and request for update and rendering !!
int main() {

	// lets just start the game .
	std::cout << "Hello , Welcome to the Balls !";

	Game game;

	while (game.isWindowOpen()) {

		game.Update();
		game.Render();
	}
	
	return 0;
}