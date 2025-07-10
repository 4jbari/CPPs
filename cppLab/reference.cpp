#include <iostream>

void use_reference(std::string& ref) {
    std::cout << ref << std::endl;
}

void use_pointer(std::string* ptr) {
    std::cout << *ptr << std::endl;
}

int main() {
    std::string brain = "HI THIS IS BRAIN";

    use_reference(brain);
    use_pointer(&brain);
}
