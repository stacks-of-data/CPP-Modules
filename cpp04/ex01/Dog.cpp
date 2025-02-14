/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:15:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:30:14 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	this->brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const std::string& sType) : Animal()
{
	this->brain = new Brain();
	this->type = sType;
	std::cout << "Dog parameterized constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal()
{
	this->brain = new Brain(obj.getBrain());
	this->type = obj.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Brain	Dog::getBrain() const
{
	return (*this->brain);
}

void	Dog::setBrain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, obj.getIdea(i));
}

Dog&	Dog::operator= (const Dog& obj)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->brain = new Brain(obj.getBrain());
	this->type = obj.getType();
	return (*this);
}