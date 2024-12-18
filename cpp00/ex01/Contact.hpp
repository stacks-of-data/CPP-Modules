/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:38 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 15:24:24 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <ctime>

class Contact
{
	private:
	std::string	darkest_secret;
	std::string phone_number;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::time_t	time;
	public:
	void SetContactData(std::string _first_name, std::string _last_name,
		std::string _nickname, std::string _phone_number, std::string _darkest_secret);
	std::string	GetContactFirstName();
	std::string	GetContactLastName();
	std::string	GetContactNickname();
	std::string	GetContactPhoneNumber();
	std::string	GetContactDarkestSecret();
	std::time_t	GetContactTimestamp();
};

#endif