#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public :
		float	toFloat( void ) const;
		int		toInt( void ) const;

		void	setRawBits( int const raw );
		int 	getRawBits( void ) const;

		Fixed(const int value);
		Fixed(const float value);
		
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other); 
		Fixed();
		~Fixed();


	private :
		int fp_num;
		static const int fractionalBits;

};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs); 

#endif