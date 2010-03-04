/*
 * Boundary.cpp
 *
 *  Created on: Jan 20, 2010
 *      Author: bieber
 */

#include "Boundary.h"
#include <cmath>

bool Boundary::collides(const Boundary& other) const{
	if(type == CIRCLE)
		if(other.type == CIRCLE)
			return circleToCircle(x, y, radius, other.x, other.y, other.radius);
		else
			return circleToRect(x, y, radius, other.x, other.y, other.width,
								other.height);
	else
		if(other.type == CIRCLE)
			return circleToRect(other.x, other.y, other.radius, x, y, width,
								height);
		else
			return rectToRect(x, y, width, height, other.x, other.y,
							  other.width, other.height);
}

bool Boundary::circleToRect(int circleX, int circleY, int radius,
							int rectangleX, int rectangleY, int width,
							int height){
	//Using disqualifying conditions
	if(circleX + radius < rectangleX)
		return false; //Circle to left of rectangle
	if(circleX - radius > rectangleX + width)
		return false; //Circle to the right of rectangle
	if(circleY + radius < rectangleY)
		return false; //Circle above rectangle
	if(circleY - radius > rectangleY + height)
		return false; //Circle below rectangle

	return true;
}

bool Boundary::circleToCircle(int x1, int y1, int r1, int x2, int y2, int r2){
	double distance = std::sqrt(std::pow(x1-y1, 2) + pow(y1-y2, 2));
	return distance < (r1 + r2); //Is the sum of the radii < the distance?
}

bool Boundary::rectToRect(int x1, int y1, int w1, int h1,
						  int x2, int y2, int w2, int h2){
	//Using disqualifying conditions
	if(x1 + w1 < x2)
		return false; //Rect #1 is to the left of Rect #2
	if(x1 > x2 + w2)
		return false; //Rect #1 is to the right of Rect #2
	if(y1 + h1 < y2)
		return false; //Rect #1 is above Rect #2
	if(y1 > y2 + h2)
		return false; //Rect #1 is below Rect #2

	return true;
}

Boundary::Boundary(int x, int y, int width, int height){
	type = RECTANGLE;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}
Boundary::Boundary(int x, int y, int radius){
	type = CIRCLE;
	this->x = x;
	this->y = y;
	this->radius = radius;
}

Boundary::Boundary(const Boundary& other){
	type = other.type;
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
	radius = other.radius;
}

Boundary::~Boundary() {
}
