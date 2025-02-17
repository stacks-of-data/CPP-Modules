/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:51:47 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 02:00:58 by amsaleh          ###   ########.fr       */
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
	std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return;
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || !this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}

AMateria*	Character::getInvSlotPtr(int index) const
{
	if (index > 3 || index < 0)
		return (0);
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