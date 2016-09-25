// Point.h
#ifndef POINT_H
#define POINT_H

# include "Defs.h"

/**
 * This class represents a single point in a two dimensional space, with (x,y)
 * coordinates. Coordinates are of type "CordType" (specified in the Defs.h
 * header)
 */

class Point
{
public:

	/**
	 * Constructor with given coordinates
	 */
	Point(const CordType x, const CordType y);

	/**
	 * Move Constructor. Required in order to enable the Array<Point> to 
	 * be movable. This is a required behavior, specifically for Array, as it
	 * needs its items to be movable as well.
	 */
	Point(Point&& other);

	/**
	 * Getter for the x coordinate.
	 * @return The x coordinate
	 */
	CordType getX() const;

	/**
	 * Getter for the y coordinate
	 * @return The y coordinate
	 */
	CordType getY() const; 
	
	/** 
	 * Two points are equal if they have the same coordinates
	 */
	bool operator==(const Point &other) const;

	/** 
	 * Two points are not equal if they don't have the same coordinates 
	 */
	bool operator!=(const Point &other) const; private:

	CordType _x;
	CordType _y;
	
};
	
#endif 
