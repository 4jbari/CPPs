#include <iostream>

class Base{
	public :

	virtual void  foo(void){
		std::cout << "in Base" << std::endl;
	}

};

class Derived : /* virtual */ public Base {
	public :

	// void foo(void) {
	// 	std::cout << "in Derived" << std::endl;
	// }
	virtual void hah(){
		std::cout << "hah in Derived" << std::endl;
	}
};

int main()
{
	Base *b = new Derived;
	b->foo();
	b->hah();

	// Derived *b = new Derived;
	// b->foo();

}