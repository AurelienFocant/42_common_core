#include "BSPNode.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	BSPNode	nd1(a, b);
	BSPNode	nd2(b, c);
	BSPNode	nd3(c, a);

	float	cross1 = nd1.crossProduct(point).toFloat();
	float	cross2 = nd2.crossProduct(point).toFloat();
	float	cross3 = nd3.crossProduct(point).toFloat();


	bool all_positive = (cross1 > 0) && (cross2 > 0) && (cross3 > 0);
    bool all_negative = (cross1 < 0) && (cross2 < 0) && (cross3 < 0);

    return (all_positive || all_negative);
}
