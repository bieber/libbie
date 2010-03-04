/*
 * Boundary.h
 *
 *  Created on: Jan 20, 2010
 *      Author: bieber
 *
 *  Models the bounds of an object
 *
 */

#ifndef BOUNDARY_H_
#define BOUNDARY_H_

class Boundary{

public:

	//A simple enum to keep track of the type of boundary
	enum Shape{
		CIRCLE,
		RECTANGLE
	};

private:

	Shape type;
	int x;
	int y;
	int width;
	int height;
	int radius;

public:

	static bool circleToRect(int circleX, int circleY, int radius,
							 int rectangleX, int rectangleY, int width,
							 int height);
	static bool circleToCircle(int x1, int y1, int r1, int x2, int y2, int r2);
	static bool rectToRect(int x1, int y1, int w1, int h1,
						   int x2, int y2, int w2, int h2);

	virtual bool collides(const Boundary& other) const;

	//Getters
	virtual Shape getType() const{ return type; }
	virtual int getX() const{ return x; }
	virtual int getY() const{ return y; }
	virtual int getWidth() const{ return width; }
	virtual int getHeight() const{ return height; }
	virtual int getRadius() const{ return radius; }

	//Setters
	virtual void addX(int dx){ x += dx; }
	virtual void addY(int dy){ y += dy; }

	Boundary(int x, int y, int width, int height);
	Boundary(int x, int y, int radius);
	Boundary(const Boundary& other);
	virtual ~Boundary();
};

#endif /* BOUNDARY_H_ */
