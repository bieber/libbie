/*
 * Game.cpp
 *
 *  Created on: Mar 16, 2010
 *      Author: bieber
 */

#include "Game.h"

#include <iostream>

Game::Game(int width, int height, const char* title):
		window(width, height, title){

	window.addEventListener(this);
	window.addKeyboardListener(this);
	window.addMouseListener(this);

	curTime = SDL_GetTicks();

	//Starting the main loop
	running = true;
	while(running){
		//Handling events
		window.processEvents();

		//Making sure at least one second passes between loops
		while(curTime >= SDL_GetTicks());

		//Calling the run function with the elapsed time
		run(SDL_GetTicks() - curTime);

		//Setting curTime again
		curTime = SDL_GetTicks();

		//Refreshing the display
		window.flip();
	}
}

Game::~Game() { }

//Mouse listener events
void Game::mouseDown(SDL_MouseButtonEvent* event){ }
void Game::mouseUp(SDL_MouseButtonEvent* event){ }
void Game::mouseMoved(SDL_MouseMotionEvent* event){ }

//Event listener event
void Game::event(SDL_Event* event){ }

//Keyboard listener events
void Game::keyDown(SDLKey key){ }
void Game::keyUp(SDLKey key){ }
