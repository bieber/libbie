/*
 * Color.h
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#ifndef COLOR_H_
#define COLOR_H_

#include "SDL/SDL.h"

class Color {
private:
	Uint8 r;
	Uint8 g;
	Uint8 b;

public:
	virtual Uint8 getR() const{ return r; }
	virtual Uint8 getG() const{ return g; }
	virtual Uint8 getB() const{ return b; }

	Color(Uint8 r, Uint8 g, Uint8 b): r(r), g(g), b(b){ }
	virtual ~Color();
};

#endif /* COLOR_H_ */
