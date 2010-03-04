/*
 * Graphics.h
 *
 *  Created on: Jan 11, 2010
 *      Author: bieber
 *
 *  Creates an SDL window and allows graphics and input operations on it
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <vector>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Image.h"
#include "Color.h"
#include "KeyboardListener.h"
#include "MouseListener.h"
#include "EventListener.h"

class Graphics{

private:
	//A global flag to determine whether an instance already exists
	static bool exists;

	//Listeners
	std::vector<KeyboardListener*> keyboardListeners;
	std::vector<MouseListener*> mouseListeners;
	std::vector<EventListener*> eventListeners;

	//Window dimensions
	int width;
	int height;

	SDL_Surface* window;

public:

	static const int bitsPerPixel = 32;

	//Input related functions
	void addKeyboardListener(KeyboardListener* listener);
	void addMouseListener(MouseListener* listener);
	void addEventListener(EventListener* listener);
	void processEvents();
	Uint8* getKeys() const{ return SDL_GetKeyState(NULL); }

	//Drawing functions
	void drawImage(const Image& img, int x, int y, SDL_Rect* mask = NULL);
	void clear(const Color& color);

	//Basic SDL functions
	void flip(){ SDL_Flip(window); }
	void pause(int milis){ SDL_Delay(milis); }

	Graphics(int width, int height, const char* title);
	virtual ~Graphics();

};


#endif /* GRAPHICS_H_ */
