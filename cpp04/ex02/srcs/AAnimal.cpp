/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:04:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 19:26:52 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& sType) : type(sType)
{
	std::cout << "AAnimal parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) : type(obj.getType())
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}

AAnimal&	AAnimal::operator= (const AAnimal& obj)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = obj.getType();
	return (*this);
}