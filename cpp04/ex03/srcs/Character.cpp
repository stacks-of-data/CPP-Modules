/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:51:47 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/19 01:28:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("DEFAULT_NAME")
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->inventory[i] = 0;
	std::cout << "Character parameterized constructor called" << std::endl;
}

Character::Character(const Character& obj) : _name(obj.getName())
{
	this->inventory[0] = obj.getInvSlotPtr(0);
	this->inventory[1] = obj.getInvSlotPtr(1);
	this->inventory[2] = obj.getInvSlotPtr(2);
	this->inventory[3] = obj.getInvSlotPtr(3);
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Materia ptr is null" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == m)
		{
			std::cout << "Materia already equipped" << std::endl;
			return;
		}
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (!this->inventory[idx])
	{
		std::cout << "Slot to unequip is empty" << std::endl;
		return;
	}
	std::cout << this->inventory[idx]->getType() << " unequipped" << std::endl;
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (!this->inventory[idx])
	{
		std::cout << "Attempt to use empty slot" << std::endl;
		return;
	}
	this->inventory[idx]->use(target);
}

AMateria*	Character::getInvSlotPtr(int index) const
{
	if (index > 3 || index < 0)
	{
		std::cout << "Invalid index" << std::endl;
		return (0);
	}
	return (this->inventory[index]);
}

Character&	Character::operator= (const Character& obj)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	this->_name = obj.getName();
	this->inventory[0] = obj.getInvSlotPtr(0);
	this->inventory[1] = obj.getInvSlotPtr(1);
	this->inventory[2] = obj.getInvSlotPtr(2);
	this->inventory[3] = obj.getInvSlotPtr(3);
	return (*this);
}