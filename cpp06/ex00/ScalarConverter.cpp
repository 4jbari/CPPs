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
	if (str.empty())
		return false;
	if ( str[i] == '-' || str[i] == '+' )
		i++;
	while ( i < str.length() && std::isdigit(str[i]))
	{
		i++;
	}
	if (i == str.length())
		return true;
	return false;
}

bool	isFloat(std::string str)
{
	size_t i = 0;
	size_t dots = 0;
	if ( str[i] == '-' || str[i] == '+' )
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
			dots++;
		else if ( !isdigit(str[i]) && str[i] != 'f')
			return false;
		i++;
	}
	if (dots == 1 && str[str.length() - 1] == 'f')
		return true;
	return false;

}

bool isDouble(std::string str)
{
	size_t i = 0;
	size_t dots = 0; 
	if ( str[i] == '-' || str[i] == '+' )
		i++;
	while (i < str.length())
	{
		if (str[i] == '.')
			dots++;
		else if ( !isdigit(str[i]) )
			{
				return false;
			}
		i++;
	}
	if (dots == 1)
		return true;
	return false;
}

literalType detectType(std::string str)
{
	std::cout << str << std::endl;
	if (str.length() == 1 && !isdigit(str[0]))
		return TYPE_CHAR;
	else if (isDigit(str))
		return TYPE_INT;
	else if (isFloat(str))
		return TYPE_FLOAT;
	else if (isDouble(str))
		return TYPE_DOUBLE;
	else if (str == "nanf" || str == "-inff" || str == "+inff")
		return TYPE_PSEUDO_FLOAT;
	else if (str == "nan" || str == "-inf" || str == "+inf")
		return TYPE_PSEUDO_DOUBLE;

	return TYPE_UNKNOWN;

}
void	printChar(double d )
{
	std::cout << "char: ";
	if (d > 127 || d < 0)
		std::cout << "impossible" << std::endl;
	else if ( d < 32 || d == 127 )
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void printInt(double d)
{
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	else 
		std::cout <<  static_cast<int>(d) << std::endl;

}

void printFloat(double d, std::string str)
{
	(void)str;
	float f = static_cast<float>(d); 
	std::cout << "float: ";
	if (f == static_cast<int>(d))
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << f << "f" << std::endl;
	}
	else
		// std::cout << std::fixed << std::setprecision(str.length());
		std::cout << static_cast<float>(d) << "f" << std::endl;

}

void	printDouble(double d, std::string str)
{
	(void)str;
	std::cout << "double: " ;
	if (d == static_cast<int>(d))
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << d << std::endl;
	}
	else
		std::cout << d << std::endl;


}

void ScalarConverter::convert(std::string str)
{
	literalType litType = detectType(str);
	char	c;
	int		i;
	float	f;
	double	d;


	switch (litType){
		case TYPE_CHAR :
			c = static_cast<char>(str[0]);
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			std::cout << "CHAR\n";
			std::cout << "char: "   << "'" << c << "'" << std::endl;
			std::cout << "int: "    << i << std::endl;
			std::cout << "float: "  << f << std::endl;
			std::cout << "double: " << d << std::endl;
			break ;
		
		case TYPE_INT : 
			std::cout << "INT\n";
			d = std::strtod(str.c_str(), NULL);
			printChar(d);
			printInt(d);
			printFloat(d, str);
			printDouble(d, str);
			break ;

		case TYPE_FLOAT : 
			std::cout << "FLOAT\n";
			f = std::strtof(str.c_str(), NULL);
			d = static_cast<double>(f);
			printChar(d);
			printInt(d);
			printFloat(d, str);
			printDouble(d, str);
			break ;
		case TYPE_DOUBLE : 
			std::cout << "DOUBLE\n";
			d = std::strtod(str.c_str(), NULL);
			printChar(d);
			printInt(d);
			printFloat(d, str);
			printDouble(d, str);
			break ;
		case TYPE_PSEUDO_FLOAT : 
			std::cout << "PSEUDOTYPE_PSEUDO_FLOAT\n";
			f = strtof(str.c_str(), NULL);
			d = static_cast<double>(f);
			
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << std::showpos;
			std::cout << "float: "  << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			std::cout << std::noshowpos;
			break ;

		case TYPE_PSEUDO_DOUBLE : 
			std::cout << "PSEUDOTYPE_PSEUDO_DOUBLE\n";
			d = strtod(str.c_str(), NULL);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << std::showpos;
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			std::cout << std::noshowpos;
			break ;
		default : 
			std::cout << "UNKNOWN TYPE" << std::endl;
	};
}


		

