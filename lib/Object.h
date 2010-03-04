/*
 * Object.h
 *
 *  Created on: Jan 12, 2010
 *      Author: bieber
 *
 *  Represents an in-game object with sprite, animation, velocity, and etc.
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "Graphics.h"
#include "Image.h"
#include "Boundary.h"

#include "SDL/SDL.h"

#include <vector>

class Object {

private:
	//Basic properties
	Image* sprite;
	double xPos;
	double yPos;
	double xVel; //X and Y velocities are measured in pixels/second
	double yVel;

	//Animation properties
	int beginFrame;
	int endFrame;
	bool frameForward;
	int currentFrame;
	double fps;
	long frameTicks;

	//Boundaries
	std::vector<Boundary> boundaries;

	int width;
	int height;

public:

	//Getters and setters
	virtual double getX() const{ return xPos; }
	virtual double getY() const{ return yPos; }
	virtual void setX(double x){ xPos = x; }
	virtual void setY(double y){ yPos = y; }
	virtual double getXVelocity() const{ return xVel; }
	virtual double getYVelocity() const{ return yVel; }
	virtual void setXVelocity(double x){ xVel = x; }
	virtual void setYVelocity(double y){ yVel = y; }
	virtual int getWidth() const{ return sprite->getWidth(); }
	virtual int getHeight() const{ return sprite->getHeight(); }

	//Dealing with animation
	virtual void setFPS(double fps);
	virtual void setFrame(int frame){ currentFrame = frame; }
	virtual void setFrameRange(int begin, int end);
	virtual void animate(long ticks);

	//Dealing with boundaries and collisions
	virtual const std::vector<Boundary>& getBoundaries() const{
		return boundaries;
	}
	virtual void addBoundary(const Boundary& bound); //Note that this function
													 //ignores x and y coords
	virtual bool collides(const Object& other);

	//More complicated movement functions
	virtual void move(double dx, double dy){
		xPos += dx;
		yPos += dy;
	}

	virtual void move(double time);

	virtual void accelerate(double dx, double dy){
		xVel += dx;
		yVel += dy;
	}

	virtual void draw(Graphics& drawTo);

	Object(Image& spriteImage, double x, double y, double xVel = 0,
		   double yVel = 0);
	virtual ~Object();
};

#endif /* OBJECT_H_ */
