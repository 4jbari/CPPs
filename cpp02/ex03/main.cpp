#include "Point.hpp"


int main( void ) 
{
	Point a (1, 2);
	Point b (3, 5);
	Point c (5, 2);
	
	Point p(4, 3);

	if(bsp(a,b,c,p))
		std::cout<< "true"<<std::endl;
	else
		std::cout<< "false" <<std::endl;
		
	return 0;
}



