// Triangle.h

/* Represents the shape of a triangle - with three points */

# include "Shape.h"
# include <array>

using namespace std;

class Triangle: public Shape
{
public:
	static const int NUMBER_OF_POINTS = 3;

	/* Constructor. Receives an array containing exactly 3 points. Receives an
	 * rvalue reference in order to copy the pointer in.*/
	Triangle(array<Point, NUMBER_OF_POINTS>&& points);
};

# endif
