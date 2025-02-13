/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:42 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 18:37:45 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap() : name(DEFAULT_TRAP_NAME),
	hit_points(10), energy_points(10), attack_dmg(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name),
	hit_points(10), energy_points(10), attack_dmg(0)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points,
		unsigned int energy_points, unsigned int attack_dmg) : name(name),
	hit_points(hit_points), energy_points(energy_points), attack_dmg(attack_dmg)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& obj) : name(obj.name),
	hit_points(obj.hit_points), energy_points(obj.energy_points),
	attack_dmg(obj.attack_dmg)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
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
		std::cout << this->name << " is destroyed" << std::endl;
		return;
	}
	if (amount > this->hit_points)
	{
		std::cout << this->name << " took " << hit_points << " damage" << std::endl;
		this->hit_points = 0;
		return;
	}
	this->hit_points -= amount;
	std::cout << this->name << " took " << amount << " damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->energy_points || !this->hit_points)
	{
		std::cout << this->name << " can't be repaired" << std::endl;
		return;
	}
	if ((static_cast<unsigned long>(this->hit_points)
		+ static_cast<unsigned long>(amount)) > std::numeric_limits<unsigned int>::max())
	{
		std::cout << "Repair amount attempt to overflow hit_points, aborting" << std::endl;
		return;
	}
	if (!amount)
	{
		std::cout << "Repair amount is 0, aborting" << std::endl;
		return;
	}
	this->energy_points--;
	this->hit_points += amount;
	std::cout << this->name << " was repaired by " << amount << std::endl;
}

std::string ClapTrap::getName()
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints()
{
	return (this->hit_points);
}

unsigned int ClapTrap::getEnergyPoints()
{
	return (this->energy_points);
}

unsigned int ClapTrap::getAttackDmg()
{
	return (this->attack_dmg);
}

ClapTrap&	ClapTrap::operator= (const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_dmg = obj.attack_dmg;
	return (*this);
}