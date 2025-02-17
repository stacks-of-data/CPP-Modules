/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:29:21 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 02:00:51 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : _type(type)
{
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