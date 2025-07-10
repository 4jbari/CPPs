#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook {
	private :
		Contact contacts[8];
	public :
		int		index;
		void	add_contacts();
		void	search();

		void	printIndex(){std::cout << index << std::endl;};
};

#endif