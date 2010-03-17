/*
 * Game.h
 *
 *  Created on: Mar 16, 2010
 *      Author: bieber
 */

#ifndef GAME_H_
#define GAME_H_

#include "KeyboardListener.h"
#include "MouseListener.h"
#include "EventListener.h"
#include "Graphics.h"

class Game: public KeyboardListener, public MouseListener,
			public EventListener {
public:
	Game(int width, int height, const char* title);
	virtual ~Game();

	//Mouse listener events
	virtual void mouseDown(SDL_MouseButtonEvent* event);
	virtual void mouseUp(SDL_MouseButtonEvent* event);
	virtual void mouseMoved(SDL_MouseMotionEvent* event);

	//Event listener event
	virtual void event(SDL_Event* event);

	//Keyboard listener events
	virtual void keyDown(SDLKey key);
	virtual void keyUp(SDLKey key);

protected:
	Graphics window;
	void kill(){ running = false; }

	//Overload this function to implement the game loop
	//dTime is the time elapsed since the last run
	virtual void run(long dTime){ }

private:
	bool running;
	long curTime;
};

#endif /* GAME_H_ */
