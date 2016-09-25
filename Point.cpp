//Point.cpp

#include "Point.h"
#include "ShapeAlgorithms.h"

// -------------------------------------------------------------------------------
// This file contains the implementation of the class Point.
// -------------------------------------------------------------------------------

/**
 * Constructor with given coordinates
 */
Point::Point(const CordType x, const CordType y): _x(x), _y(y){}

/**
 * Move Constructor
 */
Point::Point(Point&& other): Point(other._x, other._y){}

/**
 * Getter for the x coordinate
 */
CordType Point::getX() const
{
	return _x;
}

/**
 * Getter for the y coordinate
 */
CordType Point::getY() const
{
	return _y;
}

/** Two points are equal if they have the same coordinates, using
 * the ShapeAlgorithm comparison in order to allow for an epsilon of difference 
 * between the two
 * */
bool Point::operator==(const Point &other) const
{
	return compare(_x,other.getX()) == EQUALS and compare(_y,other.getY()) == EQUALS;
}


/** 
 * Two points are not equal if they don't have the same coordinates 
 */
bool Point::operator!=(const Point &other) const
{
	return !(*this == other);
}
