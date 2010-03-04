/*
 * Font.h
 *
 *  Created on: Jan 20, 2010
 *      Author: bieber
 * Loads a TTF font and uses it to draw
 */

#ifndef FONT_H_
#define FONT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include "Image.h"

class Font {

private:
	TTF_Font* data;

public:
	//Renders text to an image
	Image* render(const char* message, const Color& color) const;

	Font(const char* file, int size);
	virtual ~Font();
};

#endif /* FONT_H_ */
