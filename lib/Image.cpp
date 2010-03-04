/*
 * Image.cpp
 *
 *  Created on: Jan 11, 2010
 *      Author: bieber
 */

#include "Image.h"

void Image::init(const char* file){
	data = IMG_Load(file);
	if(!data)
		throw SDLException("Error loading image");

	//Optimizing the image for the display format
	data = SDL_DisplayFormatAlpha(data);

	//Getting the width and height
	SDL_Rect dimensions;
	SDL_GetClipRect(data, &dimensions);
	width = dimensions.w;
	height = dimensions.h;

	masks = NULL;
	numFrames = 1;
}

//Creates a new surface
Image::Image(int width, int height): width(width), height(height){
	data = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32, rMask, gMask,
								bMask, aMask);
	masks = NULL;
	numFrames = 1;
}

//A special constructor that takes an already prepared data buffer
Image::Image(SDL_Surface *img){
	data = img;

	//Getting the dimensions
	SDL_Rect dimensions;
	SDL_GetClipRect(data, &dimensions);
	width = dimensions.w;
	height = dimensions.h;

	masks = NULL;
	numFrames = 1;
}


Image::Image(const char* file, const Color& key) {
	init(file);

	//Setting the key-color
	SDL_SetColorKey(data, SDL_SRCCOLORKEY, SDL_MapRGB(data->format,
													  key.getR(),
													  key.getG(),
													  key.getB()));
}

void Image::setPixel(int x, int y, const Color& shade){

	if(x < 0 || x >= width || y < 0 || y >= height)
		throw SDLException("Pixel out of bounds");

	//We have to pack the pixels differently depending on byte order
	Uint32 pixel = 0;
	Uint32 a = 0x000000ff;
	Uint32 r = shade.getR();
	Uint32 g = shade.getG();
	Uint32 b = shade.getB();
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	g >>= 8;
	b >>= 16;
	a >>= 24;
#else
	g <<= 8;
	b <<= 16;
	a <<= 24;
#endif

	pixel = r | g | b | a;

	((Uint32*)data->pixels)[y * width + x] = pixel;

}

void Image::setMasks(int width, int height){

	this->width = width;
	this->height = height;

	SDL_Rect spriteSheetSize;

	//Establishing the frame masks
	SDL_GetClipRect(data, &spriteSheetSize);
	int spritesWide = spriteSheetSize.w / width;
	int spritesHigh = spriteSheetSize.h / height;

	numFrames = spritesWide * spritesHigh;
	masks = new SDL_Rect[numFrames];

	//Generating the masks
	for(int i=0; i < spritesHigh; i++){
		for(int j = 0; j < spritesWide; j++){
			masks[(i * spritesWide) + j].x = j * width;
			masks[(i * spritesWide) + j].y = i * height;
		}
	}

	for(int i=0; i < numFrames; i++){
		masks[i].w = width;
		masks[i].h = height;
	}
}


Image::Image(const char* file) {
	init(file);
}


Image::~Image() {
	SDL_FreeSurface(data);
	if(masks)
		delete[] masks;
}
