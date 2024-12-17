#include "PhoneBook.hpp"

int	PhoneBook::GetNewContactIndex()
{
	std::time_t	oldest_time = 0;
	int			oldest_i = 0;
	if (n_contacts_init < 8)
		return (n_contacts_init);
	oldest_time = contacts[0].time;
	for (int i = 1; i < 8; i++)
	{
		if (contacts[i].time < oldest_time)
		{
			oldest_time = contacts[i].time;
			oldest_i = i;
		}
	}
	return (oldest_i);
}

void	PhoneBook::AddContact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string darkest_secret;
	int	i = n_contacts_init < 8 ? n_contacts_init: GetNewContactIndex();
	std::cout << "First Name: ";
	std::getline(std::cin, first_name);
	std::cout << "Last Name: ";
	std::getline(std::cin, last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, phone_number);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkest_secret);
	contacts[i].SetContactData(first_name, last_name, nickname, phone_number, darkest_secret);
	if (n_contacts_init < 8)
		n_contacts_init++;
}