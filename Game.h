/*
 * Game.h
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "lib/games.h"

class Game: public KeyboardListener, public EventListener,
			public MouseListener {

private:
	//A variable to stop the game
	bool running;

	long lastTime;

	static const int width;
	static const int height;
	static const double gravity;
	static const char title[];

	Graphics window;
	Image ballSprite;
	Object ball;
	Image hBox;
	Image vBox;
	Image* message;
	Object** walls;

public:
	void run();

	//Methods for interfaces
	virtual void keyDown(SDLKey key);
	virtual void keyUp(SDLKey key);
	virtual void event(SDL_Event* event);
	virtual void mouseMoved(SDL_MouseMotionEvent* event);
	virtual void mouseDown(SDL_MouseButtonEvent* event);
	virtual void mouseUp(SDL_MouseButtonEvent* event);

	Game();
	virtual ~Game();
};

#endif /* GAME_H_ */
