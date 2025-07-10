#include "Point.hpp"

Fixed	area( const Point&  a , const Point&  b, const Point&  c)
{
	Fixed part1 = a.GetX() * ( b.GetY() - c.GetY());
	Fixed part2 = b.GetX() * ( c.GetY() - a.GetY());
	Fixed part3 = c.GetX() * ( a.GetY() - b.GetY());

	Fixed result = part1 + part2 + part3 ;

	if (result.toFloat() < 0 )
		result = result * Fixed(-1);

	return (result / Fixed(2) );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcArea  = area(a, b, c);
	Fixed	abpArea  = area(a, b, point);
	Fixed	acpArea  = area(a, c, point);
	Fixed	bcpArea  = area(b, c, point);
	Fixed   edge(0);
	if (abpArea == edge || acpArea == edge || bcpArea == edge)
		return false;
	return (abcArea == (abpArea + acpArea + bcpArea));

}