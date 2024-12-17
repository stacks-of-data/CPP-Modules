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