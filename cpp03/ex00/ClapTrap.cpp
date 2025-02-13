/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:42 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 17:06:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap() : name("DEFAULT_NAME"),
	hit_points(10), energy_points(10), attack_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name) : name(name),
	hit_points(10), energy_points(10), attack_dmg(0)
{
	std::cout << "Parameterized constructor called" << std::endl;	
}

ClapTrap::ClapTrap(ClapTrap& obj) : name(obj.name),
	hit_points(obj.hit_points), energy_points(obj.energy_points),
	attack_dmg(obj.attack_dmg)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Desstructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->energy_points || !this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " can't attack" << std::endl;
		return;
	}
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks "
		<< target << ", causing " << this->attack_dmg
			<<" points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
		return;
	}
	if (amount > this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " took " << hit_points << " damage" << std::endl;
		this->hit_points = 0;
		return;
	}
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " took " << amount << " damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energy_points || !this->hit_points)
	{
		std::cout << "ClapTrap " << this->name << " can't be repaired" << std::endl;
		return;
	}
	if ((static_cast<unsigned long>(this->hit_points)
		+ static_cast<unsigned long>(amount)) > std::numeric_limits<unsigned int>::max())
	{
		std::cout << "Repair amount attempt to overflow hit_points, aborting" << std::endl;
		return;
	}
	this->energy_points--;
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->name << " was repaired by " << amount << std::endl;
}

