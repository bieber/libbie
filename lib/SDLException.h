/*
 * SDLException.h
 *
 *  Created on: Jan 11, 2010
 *      Author: bieber
 */

#ifndef SDLEXCEPTION_H_
#define SDLEXCEPTION_H_

#include <string>

class SDLException {

private:
	std::string message;

public:

	const std::string& getMessage();

	SDLException(const char* message);
	virtual ~SDLException();
};

#endif /* SDLEXCEPTION_H_ */
