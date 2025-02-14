/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:04:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/14 23:45:53 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const std::string sType) : type(sType)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "ANIMAL SOUND" << std::endl;
}

Animal&	Animal::operator= (const Animal& obj)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = obj.getType();
	return (*this);
}