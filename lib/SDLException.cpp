/*
 * SDLException.cpp
 *
 *  Created on: Jan 11, 2010
 *      Author: bieber
 */

#include "SDLException.h"

const std::string& SDLException::getMessage(){
	return message;
}


SDLException::SDLException(const char* message) {
	this->message = std::string(message);
}

SDLException::~SDLException() {}
