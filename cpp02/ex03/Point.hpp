#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
	private :
		const Fixed	x;
		const Fixed	y;
	
	public :

		Point();
		~Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		Fixed GetX() const;
		Fixed GetY() const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);



#endif