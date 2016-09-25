// Shape.cpp


# include "Shape.h"
# include "ShapeAlgorithms.h"

using namespace std;

/** View description in header */
Shape::Shape(const int number_of_points): _number_of_points(number_of_points){}

/** View description in header */
bool Shape::validateShape(const array<Point, _number_of_points>& points)
{
	for(int i = 0; i < _number_of_points; i++)
	{
		// The last point and the first point in the array are an edge as well,
		// so modulu is used to create the cyclical effect
		if(points[i] == points[(i+1) % _number_of_points])
		{
			return false;
		}
	}

	return true;
}


/** Checks if one of the points of one shape is in the other. If so, they
 * intersect. If not - we know that one isn't contained in the other. Now we
 * check for each existing pair of edges if they intersect. If so - the shapes
 * intersect.
 */
bool Shape::doesShapeIntersect(const Shape& other) const
{
	if(_isPointInShape(other._points[0]))
	{
		return true;
	}

	if(other._isPointInShape(_points[0]))
	{
		return true;
	}

	for(int i = 0; i < _number_of_points; i++)
	{
		for(int j = 0; j < other._number_of_points; j++)
		{
			if(doLinesIntersect(_points[i], _points[(i+1) % _number_of_points], other._points[j],
						other._points[(j+1) % _number_of_points]))
			{
				return true;
			}
		}
	}

	return false;
}

/** First checks the side that the point is on in relation to the last edge
 * (the first and last points in the shape's array). Then iterates over all
 * other edges to make sure they are all on that same side */
bool Shape::_isPointInShape(const Point& point) const
{
	int side = getSideOfEdge(point, _points[_number_of_points-1], _points[0]);

	for(int i = 0; i < _number_of_points - 1; i++)
	{
		if(side != getSideOfEdge(point, _points[i], _points[i+1]))
		{
			return false;
		}
	}
	
	return true;
}
