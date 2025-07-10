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
	if ( this != &other)
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


bool	Fixed::operator>(const Fixed& other) const
{
	return (fp_num > other.fp_num);
}
bool	Fixed::operator<(const Fixed& other) const
{
	return (fp_num < other.fp_num);
}
bool	Fixed::operator>=(const Fixed& other) const
{
	return (fp_num >= other.fp_num);
}
bool	Fixed::operator<=(const Fixed& other) const
{
	return (fp_num <= other.fp_num);
}
bool	Fixed::operator==(const Fixed& other) const
{
	return (fp_num == other.fp_num);
}
bool	Fixed::operator!=(const Fixed& other) const
{
	return (fp_num != other.fp_num);
}



Fixed	Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result = Fixed(this->toFloat() * other.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result = Fixed(this->toFloat() / other.toFloat());
	return (result);
}



Fixed&	Fixed::operator++()
{
	this->fp_num++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;
	temp.fp_num = this->fp_num;
	this->fp_num++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	this->fp_num--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;
	temp.fp_num = this->fp_num;
	this->fp_num--;
	return (temp);
}



Fixed& 	Fixed::min(Fixed& lhs, Fixed& rhs)
{
	return ((lhs < rhs)? lhs : rhs);
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	return ((lhs < rhs)? lhs : rhs);
}

Fixed&	Fixed::max(Fixed& lhs, Fixed& rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	return (lhs > rhs ? lhs : rhs);
}