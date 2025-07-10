#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed {
	public :
		void setRawBits( int const raw );
		int getRawBits( void ) const;
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other); 
		Fixed();
		~Fixed();


	private :
		int 				fp_num;
		static const int	bits;

};


#endif