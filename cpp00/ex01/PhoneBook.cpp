#include "PhoneBook.hpp"


void	PhoneBook::add_contacts()
{
	std::cout << index << std::endl;
	contacts[index].add();
	if (index < 7)
		index++;
	else 
		index = 0;
}

void PhoneBook::search()
{
	int contactIndex = 0;
	int promptedIndex = 0;
	std::string is;
	if (contacts[contactIndex].is_empty())
	{
		std::cerr << "\t\t*Error :PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "   index  " << "|" << "first name"  << "|" << " last name" << "|"
			  << " nickname " << "|" << std::endl
			  << "--------------------------------------------\n";
	while (contactIndex < 8 && !contacts[contactIndex].is_empty())
	{
		contacts[contactIndex].print_row(contactIndex);
		contactIndex++;
	}

	std::cout << "--------------------------------------------\n";
	std::cout << "	*Enter the wanted index :";
	// std::cin >> promptedIndex;
	// std::cout << promptedIndex << std::endl;
	std::getline(std::cin, is);
	if (std::cin.eof())
		std::exit(0);
	for (unsigned long i = 0; i < is.size(); i++)
	{
		if (!std::isdigit(is[i]))
		{
			std::cout << "ERROR :INVALID INDEX (SHOULD BE A DIGIT)\n";
			std::cerr << "\t*EXITING SEARCH*" << std::endl;
			return ;
		}
	}
	promptedIndex = std::atoi(is.c_str());
	if  (std::cin.fail() || promptedIndex > 7 || promptedIndex < 0 || contacts[promptedIndex].is_empty())
	{
		std::cerr << "ERROR :INVALID INDEX**" << std::endl;
		std::cerr << "\t**EXITING SEARCH**" << std::endl;
		return ;
	}
	contacts[promptedIndex].print_contact();
}

int main ()
{
	std::string	cmd;

	Contact contact; 
	PhoneBook pb;
	
	pb.index = 0;
	while (cmd != "EXIT")
	{
		std::cout << "COMMADS AVAILBLE : ADD, SEARCH, EXIT.\n";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (0);
		if (cmd == "ADD")
			pb.add_contacts();
		else if (cmd == "SEARCH")
			pb.search();
	}
	return 0;
}
