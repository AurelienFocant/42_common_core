#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

bool	bsp( Point const a, Point const b, Point const c, Point const point);

void testBSP(const Point& a, const Point& b, const Point& c,
		const Point& p, bool expected, const std::string& description)
{
	bool result = bsp(a, b, c, p);
	std::cerr << description << " => "
		<< "Expected: " << (expected ? "true" : "false")
		<< ", Got: " << (result ? "true" : "false")
		<< " => " << (result == expected ? "✅" : "❌")
		<< std::endl;
}


int main( void )
{
	std::cerr << "===== bsp Geometric Tests =====" << std::endl;

	// Triangle: right-angled at origin
	Point a(0.0f, 0.0f);
	Point b(0.0f, 5.0f);
	Point c(5.0f, 0.0f);

	// Inside the triangle
	Point p1(1.0f, 1.0f); // definitely inside
	testBSP(a, b, c, p1, true, "Point inside triangle");

	// Outside the triangle
	Point p2(5.0f, 5.0f); // clearly outside
	testBSP(a, b, c, p2, false, "Point outside triangle");

	// On the edge
	Point p3(2.5f, 0.0f); // on AB
	testBSP(a, b, c, p3, false, "Point on edge AB");

	Point p4(0.0f, 2.5f); // on AC
	testBSP(a, b, c, p4, false, "Point on edge AC");

	Point p5(2.5f, 2.5f); // on BC (not really valid in this triangle, but still test)
	testBSP(a, b, c, p5, false, "Point possibly near or on edge BC");

	// At a vertex
	testBSP(a, b, c, a, false, "Point at vertex A");
	testBSP(a, b, c, b, false, "Point at vertex B");
	testBSP(a, b, c, c, false, "Point at vertex C");

	// Inside
	Point p6(0.1f, 0.1f);
	testBSP(a, b, c, p6, true, "Point inside triangle");

	// Outstide
	Point p7(-0.1f, 0.1f);
	testBSP(a, b, c, p7, false, "Point outside triangle");

	return 0;
}
