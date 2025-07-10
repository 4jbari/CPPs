#include <cstring>
#include <stdio.h>
#include <iostream>
class machine{
	public :
		void setPtr (void);
		 void print(std::string);
};





void machine::print(std::string material)
{
	std::cout << material << std::endl;
}

void machine::setPtr (void)
{

}

void test(void)
{
	std::cout << "in test" << std::endl;
	return ;
}

void (*ptrFunc[2]) (void);


int main()
{
	// ptrFunc[0] = test;
	// ptrFunc[0]();

	// printf("%p\n", test);
	// printf("%p\n", &test);
	// printf("%p\n", &ptrFunc[0]);
	
	machine a;
	void (machine::*ptrMemFun) (std::string);
	ptrMemFun = &machine::print;
	printf("%p\n", &ptrMemFun);
	printf("%p\n", *(void **)&ptrMemFun);
	std::cout << &machine::print << std::endl;
	std::cout << sizeof(ptrMemFun) << std::endl;

	(a.*ptrMemFun)("ahah\n");
// void* raw = nullptr;
// std::memcpy(&raw, &ptrMemFun, sizeof(void*));
// std::cout << "Raw address: " << raw << std::endl;


}