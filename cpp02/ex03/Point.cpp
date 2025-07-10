#include "Point.hpp"

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::Point() : x(0), y(0)
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point destructor called" << std::endl;
}

Point::Point(const Fixed& x, const Fixed& y) : x(x), y(y)
{}

Point::Point(const Point& other) : x(other.x), y(other.y)
{}

Fixed Point::GetX() const
{
	return (x);
}

Fixed Point::GetY() const
{
	return (y);
}


