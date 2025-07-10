#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;

}


ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

bool isDigit(std::string str)
{
	unsigned long i = 0;
	while ( i < str.length() && std::isdigit(str[i]))
	{
		i++;
	}
	if (i == str.length())
		return true;
	return false;

}
void ScalarConverter::convert(std::string str)
{
	if (str.length() == 0)
		std::cerr << "the argument should be a str" << std::endl;
	if (str.length() == 1)
		std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
	if (isDigit(str))
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

		

