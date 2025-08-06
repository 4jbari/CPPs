#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);


int main()
{
    // std::cout << "GENERATING ..." << std::endl;
    // Base * ran = generate();
    
    // std::cout << "IDENTIFYING WITH POINTER ..." << std::endl;
    // identify(ran);
    
    // std::cout << "IDENTIFYING WITH REFERENCE ..." << std::endl;
    // identify(*ran);

    // delete ran;


    for ( int i = 0; i < 5 ; i++)
    {
        Base* a = generate();
        identify(a);
        identify(*a);
        delete a;
    }
}