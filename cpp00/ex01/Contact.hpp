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
	public:
	std::time_t	time;
	void SetContactData(std::string _first_name, std::string _last_name,
		std::string _nickname, std::string _phone_number, std::string _darkest_secret);
};

#endif