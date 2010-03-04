/*
 * Object.cpp
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 */

#include "Object.h"

void Object::move(double time){
	double dx = (time / 1000.) * xVel;
	double dy = (time / 1000.) * yVel;
	move(dx, dy);
}


Object::Object(Image& spriteImage, double x, double y, double xVel,
			   double yVel): sprite(&spriteImage), xPos(x), yPos(y),
			   xVel(xVel), yVel(yVel){

	currentFrame = 0;

}

void Object::addBoundary(const Boundary& bound){
	boundaries.push_back(bound);
}
bool Object::collides(const Object& other){
	for(unsigned int i=0; i<other.boundaries.size(); i++){
		for(unsigned int j=0; j<boundaries.size(); j++){
			Boundary thisBound(boundaries[j]);
			thisBound.addX(xPos);
			thisBound.addY(yPos);
			Boundary otherBound(other.boundaries[i]);
			otherBound.addX(other.xPos);
			otherBound.addY(other.yPos);

			if(thisBound.collides(otherBound))
				return true;
		}
	}

	return false;
}


void Object::setFPS(double fps){
	this->fps = fps;
	frameTicks = 0;
}

//If the start frame is after the end frame, the object will animate in reverse
void Object::setFrameRange(int begin, int end){
	beginFrame = begin;
	endFrame = end;
	if(beginFrame < endFrame)
		frameForward = true;
	else
		frameForward = false;
}


void Object::animate(long ticks){
	frameTicks += ticks;
	if(frameTicks/1000. >= 1./fps){
		frameTicks = 0;
		if(frameForward){
			currentFrame++;
			if(currentFrame >= sprite->getNumFrames())
				currentFrame = 0;
		}else{
			currentFrame--;
			if(currentFrame < 0)
				currentFrame = sprite->getNumFrames() - 1;
		}
	}
}

void Object::draw(Graphics& drawTo){
	SDL_Rect* mask = NULL;
	if(sprite->getNumFrames() > 1)
		mask = sprite->getFrame(currentFrame);

	drawTo.drawImage(*sprite, xPos, yPos, mask);
}

Object::~Object() {
}
