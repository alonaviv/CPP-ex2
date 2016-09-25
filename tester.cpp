# include "Point.h"
# include "Defs.h"
# include "ShapeAlgorithms.h"
# include <vector>
# include <iostream>

using namespace std;
// Create a point with certain coordinates, and verify they are correct
bool test1()
{
	CordType x,y;
	x = 3.5;
	y = 2.54323;
	Point p(x,y);
	return p.getX() == x and p.getY() == y;
}

// Tests that two points with the same coordinates are equal
bool test2()
{
	CordType x,y;
	x = 4;
	y = 3.532543;
	Point p1(x,y);
	Point p2(x,y);
	return p1 == p2;
}

// Tests that two points with different coordinates are not equal
bool test3()
{
	CordType x1, x2, y;
	x1 = 3;
	x2 = 7.8;
	y = 4.2432;
	Point p1(x1,y);
	Point p2(x2,y);
	return p1 != p2;
}

/* Tests two intersecting lines */
bool test4()
{
	Point p1(1,1);
	Point p2(5,5);
	Point p3(1,5);
	Point p4(5,1);
	return doLinesIntersect(p1,p2,p3,p4);
}


/* Tests two non intersecting lines */
bool test5()
{
	Point p1(1,1);
	Point p2(2,2);
	Point p3(3,3);
	Point p4(4,4);
	return !doLinesIntersect(p1,p2,p3,p4);
}

/* Tests two non intersecting lines */
bool test6()
{
	Point p1(1,1);
	Point p2(2,2);
	Point p3(0,0);
	Point p4(-5, -5);
	return !doLinesIntersect(p1,p2,p3,p4);
}

/* Tests two non intersecting lines */
bool test7()
{
	Point p1(1,1);
	Point p2(2,2);
	Point p3(4,1);
	Point p4(5,2);
	return !doLinesIntersect(p1,p2,p3,p4);
}



/* Tests two intersecting lines */
bool test8()
{
	Point p1(1,1);
	Point p2(-1,-1);
	Point p3(-5,5);
	Point p4(5,-5);
	return doLinesIntersect(p1,p2,p3,p4);
}


/* Tests a point on the right side */
bool test9()
{
	Point point(1,-1);
	Point vertex1(-1,-1);
	Point vertex2(1,1);
	return getSideOfEdge(point,vertex1, vertex2) < 0;
}

/* Tests a point on the right side */
bool test10()
{
	Point point(499.9,500);
	Point vertex1(1,1);
	Point vertex2(-1,-1);
	return getSideOfEdge(point,vertex1, vertex2) < 0;
}

/* Tests a point on the left side */
bool test11()
{
	Point point(500.1,500);
	Point vertex1(1,1);
	Point vertex2(-1,-1);
	return getSideOfEdge(point,vertex1, vertex2) > 0;
}

/* Tests a point on the left side */
bool test12()
{
	Point point(500.1,500);
	Point vertex1(-1,-1);
	Point vertex2(1,1);
	return getSideOfEdge(point,vertex1, vertex2) < 0;
}

/* Tests a point on the left side */
bool test13()
{
	Point point(-1,-1);
	Point vertex1(1,-1);
	Point vertex2(-1,1);
	return getSideOfEdge(point,vertex1, vertex2) > 0;
}

/* Tests points are on the same side */
bool test14()
{
	Point point1(-1,-1);
	Point point2(-100,99);
	Point vertex1(1,-1);
	Point vertex2(-1,1);
	int k1 = getSideOfEdge(point1, vertex1, vertex2);
	int k2 = getSideOfEdge(point2, vertex1, vertex2);
	return arePointsOnSameSide(k1, k2);
}

/* Tests points are not on the same side */
bool test15()
{
	Point point1(1,-100);
	Point point2(1,2);
	Point vertex1(1,1);
	Point vertex2(50,50);
	int k1 = getSideOfEdge(point1, vertex1, vertex2);
	int k2 = getSideOfEdge(point2, vertex1, vertex2);
	return !arePointsOnSameSide(k1, k2);
}
int main()
{
	bool success = true;
	std::vector<bool (*)()> tests {test1, test2, test3, test4,test5,test6,test7,test8,test9,test10,test11,test12, test13, test14, test15};

	for(auto it = tests.begin(); it != tests.end(); it++)
	{
		if (!(**it)())
		{
			cout << "Test number " << it - tests.begin() + 1<< " has failed " << endl;
			success = false;
		}
		else
		{
			cout << "The test named " << it - tests.begin() + 1  << " has passed" << endl;
		}
	}

	if(success)
	{
		cout << "All tests passed!!" << endl;
	}
	else
	{
		cout << "Failed tests!" << endl;
	}
}
