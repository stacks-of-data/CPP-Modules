/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Air.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:30:45 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 16:04:47 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Air.hpp"
#include <iostream>

Air::Air() : AMateria("air")
{
	std::cout << "Air constructor called" << std::endl;
}

Air::Air(const Air& obj) : AMateria("air")
{
	(void)obj;
	std::cout << "Air copy constructor called" << std::endl;
}

Air::~Air()
{
	std::cout << "Air destructor called" << std::endl;
}

AMateria*	Air::clone() const
{
	return (new Air());
}

void	Air::use(ICharacter& target)
{
	std::cout << "* Summoned streams of air at " << target.getName() << " *" << std::endl;
}

Air&	Air::operator= (const Air& obj)
{
	(void)obj;
	std::cout << "Air copy assignment operator called" << std::endl;
	this->_type = "air";
	return (*this);
}