// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

/** This abstract class represents a generic geometrical shape. The shape is 
 * composed of an array of Point objects. Semantically, the edges of the shape
 * is defined by every two points next to each other in the array, cyclically. 
 * In other words, for the array [p1,p2,p3] - the edges are defined as the
 * group (p1,p2), (p2,p3), (p3,p1). Every shape has a fixed number of points,
 * and hence a fixed array size, defined by classes deriving Shape.
 * The Shape class provides the ability to check its area and to determine if
 * it intersects with another shape. 
 */

# include <array>
# include "Point.h"
# include "Defs.h"

using namespace std;

class Shape
{
public:
	/** Returns true iff given shape intersects with self */
	bool doesShapeIntersect(const Shape& other) const;
			
	/** Returns the area of the shape. To be implemented according to the
	 * derived specific shape.*/
	virtual CordType getArea() const; 

protected:
	/** Constructor. Receives an array of the shapes points. Moves the array
	 * into the object */
	Shape(const int number_of_points);

	/**
	 * Receives a reference to an array of points that is meant to be used to 
	 * construct a shape object. Validates the array by making sure all edges
	 * are larger than zero.  * Note: A better implementation would be to perform validation within the
	 * constructor and throw an exception, but these haven't been taught in
	 * class yet.
	 */
	static bool validateShape(const array<Point, _number_of_points>& points);

private:

	/*
	 * Returns true iff the given point is contained within the shape's area 
	 */
	bool _isPointInShape(const Point& point) const;
	array<Point, _number_of_points> _points;		
	const int _number_of_points;

};
# endif
