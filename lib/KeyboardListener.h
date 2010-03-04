/*
 * KeyboardListener.h
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#ifndef KEYBOARDLISTENER_H_
#define KEYBOARDLISTENER_H_

#include "SDL/SDL.h"

class KeyboardListener {
public:
	virtual void keyDown(SDLKey key) = 0;
	virtual void keyUp(SDLKey key) = 0;
};

#endif /* KEYBOARDLISTENER_H_ */
