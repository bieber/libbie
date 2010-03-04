/*
 * Image.h
 *
 *  Created on: Jan 11, 2010
 *      Author: bieber
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include "SDL/SDL_image.h"
#include "SDL/SDL.h"

#include "SDLException.h"
#include "Color.h"

class Image {

private:
	SDL_Surface* data;

	SDL_Rect* masks;

	int numFrames;
	int width;
	int height;

	void init(const char* file);

public:
	//Mask constants depend on endian-ness of the system
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    static const int rMask = 0xff000000;
    static const int gMask = 0x00ff0000;
    static const int bMask = 0x0000ff00;
    static const int aMask = 0x000000ff;
#else
    static const int rMask = 0x000000ff;
    static const int gMask = 0x0000ff00;
    static const int bMask = 0x00ff0000;
    static const int aMask = 0xff000000;
#endif

	//Getters
	virtual SDL_Surface* getData() const{ return data; }
	Uint32 getPixel(int x, int y) const{
		if(x < 0 || x >= width || y < 0 || y >= height)
			throw SDLException("Pixel out of bounds");
		return ((Uint32*)data->pixels)[y * width + x];
	}

	//Setter for pixel data
	void setPixel(int x, int y, const Color& shade);

	//Animation data
	virtual void setMasks(int width, int height);
	virtual int getNumFrames() const{ return numFrames; }
	virtual SDL_Rect* getFrame(int frame) const{
		if(frame < 0 || frame >= numFrames)
			throw SDLException("Frame out of bounds");
		return &masks[frame];
	}
	virtual int getWidth() const{ return width; }
	virtual int getHeight() const{ return height; }

	Image(const char* file, const Color& key);
	Image(const char* file);
	Image(int width, int height);
	Image(SDL_Surface* img);
	virtual ~Image();
};

#endif /* IMAGE_H_ */
