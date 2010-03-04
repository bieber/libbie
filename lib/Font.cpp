/*
 * Font.cpp
 *
 *  Created on: Jan 20, 2010
 *      Author: bieber
 */

#include "Font.h"

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

Image* Font::render(const char* message, const Color& color) const{
	SDL_Color colStruct;
	colStruct.r = color.getR();
	colStruct.g = color.getG();
	colStruct.b = color.getB();
	return new Image(TTF_RenderText_Solid(data, message, colStruct));
}

Font::Font(const char* file, int size){
	data = TTF_OpenFont(file, size);
	if(!data)
		throw SDLException("Error loading font file");

}

Font::~Font(){
	TTF_CloseFont(data);
}
