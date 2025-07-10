#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
	private :
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string PhoneNumber;
		std::string	darkest_secret;
	public :
		void	add();
		void	print_row(int index);
		void	print_contact();
		bool	is_empty();
};

#endif
