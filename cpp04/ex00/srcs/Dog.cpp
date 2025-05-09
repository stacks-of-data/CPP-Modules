/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:15:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/16 21:46:15 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string& sType) : Animal(sType)
{
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal()
{
	this->type = obj.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Dog&	Dog::operator= (const Dog& obj)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = obj.getType();
	return (*this);
}