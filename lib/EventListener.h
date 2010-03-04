/*
 * EventListener.h
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#ifndef EVENTLISTENER_H_
#define EVENTLISTENER_H_

class EventListener {
public:
	virtual void event(SDL_Event* event) = 0;
};

#endif /* EVENTLISTENER_H_ */
