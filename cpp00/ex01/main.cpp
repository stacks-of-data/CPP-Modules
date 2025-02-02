/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:35 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/01 17:43:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook *phone_book = new PhoneBook;
	while (true)
	{
		std::string	cmd;
		std::cout << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (!CheckInputErrors(true))
			break;
		if (!cmd.compare("ADD"))
			phone_book->AddContact();
		if (!cmd.compare("SEARCH"))
			phone_book->SearchContacts();
		if (!cmd.compare("EXIT") || !CheckInputErrors(true))
			break;
	}
	delete phone_book;
	return (0);
}