/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:29:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 16:03:58 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("DEFAULT_TYPE")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	if (type.empty())
	{
		std::cout << "Materia type is empty, default type will be used" << std::endl;
		this->_type = "DEFAULT_TYPE";
	}
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "UNKNOWN MATERIAL" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

AMateria&	AMateria::operator= (const AMateria& obj)
{
	std::string	type = obj.getType();
	if (type.empty())
	{
		std::cout << "Materia type is empty, default type will be used" << std::endl;
		this->_type = "DEFAULT_TYPE";
	}
	else
		this->_type = type;
	std::cout << "AMateria copy assignment operator called" << std::endl;
	return (*this);
}