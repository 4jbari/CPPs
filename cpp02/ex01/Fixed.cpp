#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : fp_num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fp_num = other.fp_num;
	return *this;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fp_num;
}


void Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	fp_num = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fp_num = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	fp_num = roundf(value * (1 << fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.toFloat();
	return os;
}

float	Fixed::toFloat( void ) const
{
	return (fp_num / ((float)(1 << fractionalBits)));
}

int		Fixed::toInt( void ) const
{
	return (fp_num / (1 << fractionalBits));
}

