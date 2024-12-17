#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"

class	PhoneBook
{
	private:
	Contact	contacts[8];
	int		n_contacts_init = 0;
	int		GetNewContactIndex();
	public:
	void	AddContact();
};

#endif