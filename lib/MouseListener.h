/*
 * MouseListener.h
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#ifndef MOUSELISTENER_H_
#define MOUSELISTENER_H_

class MouseListener {
public:
	virtual void mouseDown(SDL_MouseButtonEvent* event) = 0;
	virtual void mouseUp(SDL_MouseButtonEvent* event) = 0;
	virtual void mouseMoved(SDL_MouseMotionEvent* event) = 0;
};

#endif /* MOUSELISTENER_H_ */
