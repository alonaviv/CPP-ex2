// ShapeAlgorithms.cpp

# include <cmath>
# include "ShapeAlgorithms.h"

/** See header for description */
int compare(const CordType a, const CordType b)
{

	CordType difference = a - b;
	
	if(fabs(difference) <  EPSILON)
	{
		return EQUALS;
	}

	if(difference < 0)
	{
		return SMALLER_THAN;
	}

	return LARGER_THAN;
}


/** Calculating determinant of the matrix described in header. 
 * This is done by calculating the "major diagonal" - the sum of the diagonals
 * going down, and subtracting the sum of the "minor diagonal" - the sum of all
 * diagonals going down. */
CordType calculateCoordinateDeterminant(const Point& p1, const Point& p2, const Point& p3)
{
	CordType majorDiagonal = p1.getX()*p2.getY() + p1.getY()*p3.getX() + p2.getX()*p3.getY();	
	CordType minorDiagonal = p3.getX()*p2.getY() + p3.getY()*p1.getX() + p2.getX()*p1.getY();
	CordType determinant = majorDiagonal - minorDiagonal;
	return determinant*0.5;
}

/** Two lines (p1,p2), (p3,p4) intersect if p1 and p2 are on different sides of
 * (p3,p4) and vice versa 
 */
bool doLinesIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
{
	// Checking the side of edge (p3,p4)
	if(arePointsOnSameSide(getSideOfEdge(p1,p3,p4), getSideOfEdge(p2,p3,p3)))
	{
		return false;
	}

	// Checking the side of edge (p1,p2)
	if(arePointsOnSameSide(getSideOfEdge(p3,p1,p2), getSideOfEdge(p4,p1,p2)))
	{
		return false;
	}

	return true;
}

/** The point is on the left side of the edge if the determinant calculation
 * for the three points (the point and the two vertices) is negative. On the
 * right is negative, and on the line is 0. So function returns 1,0 or -1
 * according to the sign of the result. The comparison is done up until
 * epsilon, as defined in defs.h 
 */
int getSideOfEdge(const Point& point, const Point& vertex1, const Point& vertex2)
{
	return compare(calculateCoordinateDeterminant(point, vertex1, vertex2), 0);
}	

/** See description in header */
bool arePointsOnSameSide(const int k1, const int k2)
{
	return k1 == k2;
}
	


