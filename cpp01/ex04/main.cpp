#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "program takes a filename and two strings, s1 and s2." << std::endl;
		return (1);
	}
	if (av[2][0] == '\0')
	{
		std::cout << "s1 shouldn't be empty" << std::endl;
		return (1);
	}
	std::string fileContent = readFile(av[1]);
	std::string output = searchAndReplace(fileContent, av[2], av[3]);
	std::ofstream outFile1(std::string(av[1]) + std::string(".replace"));
	if (!outFile1.is_open())
	{
		std::cout << "failed to open " << std::string(av[1]) + std::string(".replace") << std::endl;
		return (1);
	}
	outFile1 << output;
	outFile1.close();
	
}