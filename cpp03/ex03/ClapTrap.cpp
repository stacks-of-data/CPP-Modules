/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:42 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 22:54:06 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap() : name(DEFAULT_TRAP_NAME),
	hit_points(INIT_HIT_POINTS), energy_points(INIT_ENERGY_POINTS), attack_dmg(INIT_ATTACK_DMG)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name) : name(name),
	hit_points(INIT_HIT_POINTS), energy_points(INIT_ENERGY_POINTS), attack_dmg(INIT_ATTACK_DMG)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points,
		unsigned int energy_points, unsigned int attack_dmg) : name(name),
	hit_points(hit_points), energy_points(energy_points), attack_dmg(attack_dmg)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& obj) : name(obj.getName()),
	hit_points(obj.getHitPoints()), energy_points(obj.getEnergyPoints()),
	attack_dmg(obj.getAttackDmg())
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

std::string ClapTrap::getName() const
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->energy_points);
}

unsigned int ClapTrap::getAttackDmg() const
{
	return (this->attack_dmg);
}

ClapTrap&	ClapTrap::operator= (const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_dmg = obj.getAttackDmg();
	return (*this);
}