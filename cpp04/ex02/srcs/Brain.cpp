/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:42:30 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/16 21:16:55 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const std::string *ideas_arr)
{
	std::cout << "Brain parameterized constructor called" << std::endl;
	if (!ideas_arr)
	{
		std::cerr << "ptr is NULL" << std::endl;
		return;
	}
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ideas_arr[i];
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.getIdea(i);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdea(const int index) const
{
	if (index < 0 || index > 99)
	{
		std::cerr << "Invalid index for idea" << std::endl;
		return (std::string(""));
	}
	return (this->ideas[index]);
}

void	Brain::setIdea(const int index, const std::string& sIdea)
{
	if (index < 0 || index > 99)
	{
		std::cerr << "Invalid index for idea" << std::endl;
		return;
	}
	this->ideas[index] = sIdea;
}

Brain&	Brain::operator= (const Brain& obj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.getIdea(i);
	return (*this);
}