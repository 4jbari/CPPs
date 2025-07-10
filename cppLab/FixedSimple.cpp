#include <iostream>
#include <cmath>
#include <bitset>

int main() {
    float f = 1.5f;
    int fixed = f * 2;
    std::cout << "Binary: " << std::bitset<16>(fixed) << std::endl;
	fixed = roundf(f * 256);
    std::cout << "Raw fixed int: " << fixed << std::endl;
    std::cout << "Binary: " << std::bitset<16>(fixed) << std::endl;

    float back = fixed / 256.0f;
    std::cout << "Back to float: " << back << std::endl;

	std::cout << "printing from int ::" << fixed / 256 << "." << (((fixed >> 8 ) & 1)? 5: 0) << std::endl;
}

