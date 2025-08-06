#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


Base * generate(void)
{
    static bool seeded = false ;
    if (!seeded)
    {
        std::srand(time(NULL));
        seeded = true ;
    }
    int random = std::rand() % 3;
    switch (random)
    {
        case 0:
            std::cout << "generate A" << std::endl;
            return (new A);
        case 1:
            std::cout << "generate B" << std::endl;
            return (new B);
        case 2:
            std::cout << "generate C" << std::endl;
            return (new C);
        default :
            return NULL;
    }

}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type is: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is: C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;

}

void identify(Base& p)
{

    try {
        dynamic_cast<A&>(p);
        std::cout << "Type is: A" << std::endl;
        return ;
    }
    catch(...){}
    
    try {
        dynamic_cast<B&>(p);
        std::cout << "Type is: B" << std::endl;
        return ;
    }
    catch(...){}

    try {
        dynamic_cast<C&>(p);
        std::cout << "Type is: C" << std::endl;
        return ;
    }
    catch(...){}

    std::cout << "Unknown type" << std::endl;

}