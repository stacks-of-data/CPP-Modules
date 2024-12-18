/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:26 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 20:02:25 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::GetNewContactIndex()
{
	std::time_t	oldest_time = contacts[0].time;
	int			oldest_i = 0;
	if (n_contacts_init < 8)
		return (n_contacts_init);
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
	if (!CheckInputErrorsStr(first_name) || !CheckName(first_name)) return;
	std::cout << "Last Name: ";
	std::getline(std::cin, last_name);
	if (!CheckInputErrorsStr(last_name) || !CheckName(last_name)) return;
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (!CheckInputErrorsStr(nickname) || !CheckNickname(nickname)) return;
	std::cout << "Phone Number: ";
	std::getline(std::cin, phone_number);
	if (!CheckInputErrorsStr(phone_number) || !CheckPhoneNumber(phone_number)) return;
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkest_secret);
	if (!CheckInputErrorsStr(darkest_secret)) return;
	contacts[i].SetContactData(first_name, last_name, nickname, phone_number, darkest_secret);
	if (n_contacts_init < 8)
		n_contacts_init++;
	std::cout << "New contact was added successfully!\n";
}

void	PhoneBook::SearchContacts()
{
	std::string	input;
	int			i_input;
	if (n_contacts_init == 0)
	{
		std::cout << "No contacts to search for, Add a new contact before searching.\n";
		return ;
	}
	std::cout << std::setw(10) << std::left << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << '\n';
	for (int i = 0; i < n_contacts_init; i++)
	{
		std::string	first_name = contacts[i].GetContactFirstName();
		std::string	last_name = contacts[i].GetContactLastName();
		std::string	nickname = contacts[i].GetContactNickname();
		TruncateStr(&first_name);
		TruncateStr(&last_name);
		TruncateStr(&nickname);
		std::cout << std::setw(10) << std::left << i + 1 << "|";
		std::cout << std::setw(10) << first_name << "|";
		std::cout << std::setw(10) << last_name << "|";
		std::cout << std::setw(10) << nickname << '\n';
	}
	std::cout << "Enter an contact index from 1-8 to get the full contact info: ";
	do
	{
		std::getline(std::cin, input);
		if (!CheckInputErrorsStr(input) || !CheckSearchIndexInput(input)) return;
		i_input = input[0] - '0';
		if (n_contacts_init < i_input)
		{
			std::cerr << "Contact doesn't exist, try again: ";
			continue;
		}
		break;
	} while (true);
	std::cout << i_input << '\n';
	std::cout << "First Name: " << contacts[i_input - 1].GetContactFirstName() << '\n';
	std::cout << "Last Name: " << contacts[i_input - 1].GetContactLastName() << '\n';
	std::cout << "Nickname: " << contacts[i_input - 1].GetContactNickname() << '\n';
	std::cout << "Phone Number: " << contacts[i_input - 1].GetContactPhoneNumber() << '\n';
	std::cout << "Darkest Secret: " << contacts[i_input - 1].GetContactDarkestSecret() << '\n';
	std::cout << "Press ENTER to continue!";
	getchar();
}