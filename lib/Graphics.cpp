/*
 * Graphics.cpp
 *
 *  Created on: Jan 11, 2010
 *      Author: bieber
 */

#include "Graphics.h"
#include "SDLException.h"

bool Graphics::exists = false;

void Graphics::addKeyboardListener(KeyboardListener* listener){
	keyboardListeners.push_back(listener);
}

void Graphics::addMouseListener(MouseListener* listener){
	mouseListeners.push_back(listener);
}

void Graphics::addEventListener(EventListener* listener){
	eventListeners.push_back(listener);
}

void Graphics::processEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		std::vector<KeyboardListener*>::iterator ki;
		std::vector<MouseListener*>::iterator mi;
		std::vector<EventListener*>::iterator ei;
		switch(event.type){
		case SDL_KEYDOWN:
			for(ki = keyboardListeners.begin(); ki != keyboardListeners.end();
				ki++)
				(*ki)->keyDown(event.key.keysym.sym);
			break;

		case SDL_KEYUP:
			for(ki = keyboardListeners.begin(); ki != keyboardListeners.end();
				ki++)
				(*ki)->keyUp(event.key.keysym.sym);
			break;

		case SDL_MOUSEBUTTONDOWN:
			for(mi = mouseListeners.begin(); mi != mouseListeners.end(); mi++)
				(*mi)->mouseDown(&(event.button));
			break;

		case SDL_MOUSEBUTTONUP:
			for(mi = mouseListeners.begin(); mi != mouseListeners.end(); mi++)
				(*mi)->mouseUp(&(event.button));
			break;

		case SDL_MOUSEMOTION:
			for(mi = mouseListeners.begin(); mi != mouseListeners.end(); mi++)
				(*mi)->mouseMoved(&(event.motion));
			break;

		default:
			for(ei = eventListeners.begin(); ei != eventListeners.end(); ei++)
				(*ei)->event(&event);

		}
	}
}

void Graphics::drawImage(const Image& img, int x, int y, SDL_Rect* mask){

	SDL_Rect destination;
	destination.x = x;
	destination.y = y;

	SDL_BlitSurface(img.getData(), mask, window, &destination);
}

void Graphics::clear(const Color& color){
	SDL_Rect dim;
	SDL_GetClipRect(window, &dim);
	SDL_FillRect(window, &dim, SDL_MapRGB(window->format, color.getR(),
													      color.getG(),
														  color.getB()));
}

Graphics::Graphics(int width, int height, const char* title): width(width),
															  height(height){

	//If another instance already exists, we need to bail out
	if(exists)
		throw SDLException("Multiple Graphics objects instantiated");
	else
		exists=true;

	//Initializing SDL and creating the window surface
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	window = SDL_SetVideoMode(width, height, bitsPerPixel, SDL_SWSURFACE);
	if(!window)
		throw SDLException("Error creating window");
	SDL_WM_SetCaption(title, NULL);

}

Graphics::~Graphics() {
	//Freeing the window surface and killing SDL
	SDL_FreeSurface(window);
	SDL_Quit();
	TTF_Quit();
	exists=false;
}
