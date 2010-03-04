/*
 * Game.cpp
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#include <iostream>

#include "Game.h"

//Constants
const int Game::width = 640;
const int Game::height = 480;
const double Game::gravity = 470;
const char Game::title[] = "Game";

Game::Game(): window(width, height, title), ballSprite("res/ball.png"),
			  ball(ballSprite, 60, 300, 300, -500), hBox("res/hbox.png"),
			  vBox("res/vbox.png"){
	window.addKeyboardListener(this);
	window.addEventListener(this);
	window.addMouseListener(this);
	ballSprite.setMasks(50, 50);
	walls = new Object*[4];
	walls[0] = new Object(hBox, 0, 0);
	walls[0]->addBoundary(Boundary(0, 0, 640, 20));
	walls[1] = new Object(hBox, 0, 460);
	walls[1]->addBoundary(Boundary(0, 0, 640, 20));
	walls[2] = new Object(vBox, 0, 20);
	walls[2]->addBoundary(Boundary(0, 0, 20, 440));
	walls[3] = new Object(vBox, 620, 20);
	walls[3]->addBoundary(Boundary(0, 0, 20, 440));

	running = true;
	lastTime = SDL_GetTicks();
	ball.setFPS(4);
	ball.addBoundary(Boundary(25, 25, 25));
	Font bFont("res/BiebersFont.ttf", 40);
	message = bFont.render("{Test Message}", Color(0, 0, 0));
}

Game::~Game() {
	for(int i=0; i<4; i++)
		delete walls[i];
	delete[] walls;
	delete message;
}

void Game::run(){
	while(running){
		ball.accelerate(0, (gravity/1000.) * (SDL_GetTicks() - lastTime));
		ball.move(SDL_GetTicks() - lastTime);
		ball.animate(SDL_GetTicks() - lastTime);

		if(ball.collides(*(walls[0])) || ball.collides(*(walls[1])))
			ball.setYVelocity(-ball.getYVelocity());
		if(ball.collides(*(walls[2])) || ball.collides(*(walls[3])))
			ball.setXVelocity(-ball.getXVelocity());

		lastTime = SDL_GetTicks();

		window.clear(Color(255, 255, 255));
		Image test(50, 50);
		for(int i=0; i<50; i++)
			for(int j=0; j<50; j++)
				test.setPixel(i, j, Color(255, 0,100));
		window.drawImage(test, 50, 50);
		window.drawImage(*message, 100, 100);
		ball.draw(window);
		for(int i=0; i<4; i++)
			walls[i]->draw(window);
		window.flip();
		window.processEvents();
	}
}

//Event listener interfaces

void Game::keyDown(SDLKey key){
	if(key == SDLK_ESCAPE)
		running = false;
}
void Game::keyUp(SDLKey key){
}

void Game::event(SDL_Event* event){
	if(event->type == SDL_QUIT)
		running = false;
}

void Game::mouseMoved(SDL_MouseMotionEvent* event){ }
void Game::mouseDown(SDL_MouseButtonEvent* event){ }
void Game::mouseUp(SDL_MouseButtonEvent* event){ }
