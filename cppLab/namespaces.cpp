#include <iostream>

namespace ns2{
	void func(){
		std::cout << "in 2" << std::endl;
	}
}

namespace ns1{
	void func(){
		std::cout << "in 1" << std::endl;
	}
};

namespace ns2{
	void func1(){
		std::cout << "in 2 with func 1" << std::endl;

	}
}

int main()
{
	ns1::func();
	ns2::func();
	ns2::func1();

}