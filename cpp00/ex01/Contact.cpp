#include <stdio.h>
#include "PhoneBook.hpp"

std::string myTrim(std::string info)
{
	size_t start = info.find_first_not_of(" \t\n");
	size_t end = info.find_last_not_of (" \t\n");

	return info.substr(start, end - start + 1);
}

int 	is_empty(std::string prompt)
{
	size_t iterator = prompt.find_first_not_of(" \t\n");
	if (iterator == prompt.npos)
		return 1;
	return 0;
}

std::string GetInfo(std::string prompt)
{
	std::string info;
	std::cout << prompt;

	std::getline(std::cin, info);
	if ( std::cin.eof())
		std::exit(0);
	while (is_empty(info) || info.size() == 0 ){
		std::cerr << "you should fill the information" << std::endl;
		std::cout << prompt;
		std::getline(std::cin, info);
		if ( std::cin.eof())
			std::exit(0);
	}
	info = myTrim(info);
	return (info);
}

bool	Contact::is_empty()
{
	return firstname.empty();
}

std::string truncate(std::string returned_str)
{
	if (returned_str.size() > 10)
		return (returned_str.substr(0, 9) + ".");
	return (returned_str);
}
void Contact::print_row(int index)
{
	std::cout << std::setw(10) << index << "|" ;
	std::cout << std::setw(10) << truncate(firstname) << "|";
	std::cout << std::setw(10) << truncate(lastname) << "|" ;
	std::cout << std::setw(10) << truncate(nickname) << "|" ;
	std::cout << std::endl;
}


void Contact::print_contact()
{
	std::cout << std::endl;
	std::cout << " firstname     :" << firstname << std::endl;
	std::cout << " lastname      :" << lastname << std::endl;
	std::cout << " nickname      :" << nickname << std::endl;
	std::cout << " PhoneNumber   :" << PhoneNumber << std::endl;
	std::cout << " DarkestSecret :" << darkest_secret << std::endl;

}

bool isEmpty(std::string phoneNumber)
{
	std::cout << "input : "<<phoneNumber << std::endl;
	return phoneNumber.empty();
}

bool	isNumber (std::string phoneNumber)
{
	if (phoneNumber.empty())
	{
		return false ;
	}
	for (unsigned long i = 0; i < phoneNumber.size(); i++)
	{
		if (!std::isdigit(phoneNumber[i]))
		{
			return false;
		}
	}
	return true;
}

std::string GetNumber(std::string prompt)
{
	std::string phoneNumber;
	int			notNumber = 1;
	while (notNumber)
	{
		notNumber = 0;
		std::cout << prompt;
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			std::exit(0);
		if (is_empty(phoneNumber) || phoneNumber.size() == 0)
		{
			std::cerr << "you should fill the information" << std::endl;
			notNumber = 1;
			continue;
		}
		phoneNumber = myTrim(phoneNumber);
		if (isNumber(phoneNumber))
		{
			break ;
		}
		else if (phoneNumber[0] == '+' && isNumber(phoneNumber.c_str() + 1))
		{
			break;
		}
		else 
		{
			std::cerr << "*PHONENUMBER MUST CONTAIN DIGITS" << std::endl;

			notNumber = 1;
		}
	}
	return phoneNumber;
}

void Contact::add()
{
	std::string	info;

	std::cout << "enter the contact infos:" << std::endl;

	firstname = GetInfo("first name :");
	lastname = GetInfo("last name  :");
	nickname = GetInfo("nickname   :");
	PhoneNumber = GetNumber("PhoneNumber:");
	darkest_secret = GetInfo("darkest secret :");
}