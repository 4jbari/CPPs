#include "sed.hpp"
#include <unistd.h>

std::string readFile(std::string fileName)
{
	std::string fileContent;
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		std::cout << "failed to open " << fileName << std::endl;
		std::exit(1);
	}
	
	std::string line;
	std::getline(inputFile, line);
	fileContent += line ;
	while (std::getline(inputFile, line))
	{
		fileContent += '\n';
		fileContent += line;
	}
	inputFile.close();
	return fileContent;
}

std::string	searchAndReplace(std::string str, std::string s1, std::string s2)
{
	std::string result;
	size_t	pos = 0;

	size_t	found = str.find(s1, pos);
	while (found != std::string::npos)
	{
		result += str.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
		found = str.find(s1, pos);
	}
	result += str.substr(pos, str.length());
	return result; 
}