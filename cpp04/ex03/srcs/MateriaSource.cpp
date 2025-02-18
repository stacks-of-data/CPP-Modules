/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:27:33 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 16:10:26 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia_arr[i] = 0;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource& obj)
{
	for (int i = 0; i < 4; i++)
	{
		this->materia_arr[i] = obj.createMateria(i);
		if (this->materia_arr[i])
			this->types_arr[i] = this->materia_arr[i]->getType();
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete materia_arr[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia_ptr)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materia_arr[i])
		{
			this->materia_arr[i] = materia_ptr;
			this->types_arr[i] = materia_ptr->getType();
			return;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materia_arr[i])
		{
			std::cout << "Materia type is unknown" << std::endl;
			return (0);
		}
		if (!this->types_arr[i].compare(type))
			return (this->materia_arr[i]->clone());
	}
	std::cout << "Materia type is unknown" << std::endl;
	return (0);
}

AMateria*	MateriaSource::createMateria(const int& index)
{
	if (!this->materia_arr[index])
	{
		std::cout << "Materia type is unknown" << std::endl;
		return (0);
	}
	return (this->materia_arr[index]->clone());
}

MateriaSource&	MateriaSource::operator= (MateriaSource& obj)
{
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->materia_arr[i] = obj.createMateria(i);
		if (this->materia_arr[i])
			this->types_arr[i] = this->materia_arr[i]->getType();
	}
	return (*this);
}