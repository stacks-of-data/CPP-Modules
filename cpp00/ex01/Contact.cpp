/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:41 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 15:23:58 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::SetContactData(std::string _first_name, std::string _last_name,
	std::string _nickname, std::string _phone_number, std::string _darkest_secret)
{
	first_name = _first_name;
	last_name = _last_name;
	nickname = _nickname;
	phone_number = _phone_number;
	darkest_secret = _darkest_secret;
	std::time(&time);
}

std::string	Contact::GetContactFirstName()
{
	return (first_name);
}
std::string	Contact::GetContactLastName()
{
	return (last_name);
}
std::string	Contact::GetContactNickname()
{
	return (nickname);
}

std::string	Contact::GetContactPhoneNumber()
{
	return (phone_number);
}

std::string	Contact::GetContactDarkestSecret()
{
	return (darkest_secret);
}

std::time_t Contact::GetContactTimestamp()
{
	return (time);
}