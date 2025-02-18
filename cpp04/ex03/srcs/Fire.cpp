/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:30:45 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 16:04:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Fire.hpp"
#include <iostream>

Fire::Fire() : AMateria("fire")
{
	std::cout << "Fire constructor called" << std::endl;
}

Fire::Fire(const Fire& obj) : AMateria("fire")
{
	(void)obj;
	std::cout << "Fire copy constructor called" << std::endl;
}

Fire::~Fire()
{
	std::cout << "Fire destructor called" << std::endl;
}

AMateria*	Fire::clone() const
{
	return (new Fire());
}

void	Fire::use(ICharacter& target)
{
	std::cout << "* Shoot fire elements at " << target.getName() << " *" << std::endl;
}

Fire&	Fire::operator= (const Fire& obj)
{
	(void)obj;
	std::cout << "Fire copy assignment operator called" << std::endl;
	this->_type = "fire";
	return (*this);
}