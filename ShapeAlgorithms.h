// ShapeAlgorithms.h

# include "Point.h"
# include "Defs.h"

const int SMALLER_THAN = -1;
const int LARGER_THAN = 1;
const int EQUALS = 0;

/** This module provides algorithms for calculating the relationships between
 * points and edges on a Cartesian graph. To be used eventually for determining
 * the area of a shape and if two shapes intersect.
 */

/** 
 * Receives 4 Point object, [p1, p2, p3, p4] which 
 * represent two edges defined by (p1,p2), (p3,p4). 
 * Returns true iff the two lines intersect
 */
bool doLinesIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

/**
 * Receives three Point objects - [point, vertex1, vertex2]. The two
 * vertices define a single edge. 
 * Returns the which side of the edge the vertex is located.  
 * If result < 0  - The point is on the right side.
 * If result > 0 - The point is on the left side.
 * If result == 0 - The point is on the edge itself
 */
int getSideOfEdge(const Point& point, const Point& vertex1, const Point& vertex2);    
		
/**
 * Returns 0.5 times the determinant of the matrix with the vector of all the x
 * coordinates of the three given points, all the y coordinates of the given points,
 * and the 1 vector. 
 */
CordType calculateCoordinateDeterminant(const Point& p1, const Point& p2, const Point& p3);

/**
 * Receives the result of getSideOfEdge (an integer that specifies the side of
 * a Point in comparison to a certain line) for two different
 * comparison to the same line, and returns true iff the two points are on the
 * same side of that line. Behavior undefined if one of the points is on the
 * line (i.e k==0)
 */
bool arePointsOnSameSide(const int k1, const int k2);


/**
 * Comparison function. Returns -1 if a is smaller than b, returns 0 if a
 * equals b, and returns 1 if a is bigger than b. Comparison is within the
 * limit of epsilon (as defined in defs.h). Meaning, if the difference between
 * the two is less than epsilon they are de-facto equal to each other.
 */
int compare(const CordType a, const CordType b);
