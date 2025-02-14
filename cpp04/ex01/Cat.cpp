/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:15:39 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:30:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const std::string& sType) : Animal()
{
	this->brain = new Brain();
	this->type = sType;
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal()
{
	this->brain = new Brain(obj.getBrain());
	this->type = obj.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain	Cat::getBrain() const
{
	return (*this->brain);
}

void	Cat::setBrain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->brain->setIdea(i, obj.getIdea(i));
}

Cat&	Cat::operator= (const Cat& obj)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->brain = new Brain(obj.getBrain());
	this->type = obj.getType();
	return (*this);
}