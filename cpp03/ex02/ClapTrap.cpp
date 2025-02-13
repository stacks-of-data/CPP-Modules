/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:02:42 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/14 00:14:14 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap() : _name(DEFAULT_TRAP_NAME),
	_hit_points(INIT_HIT_POINTS), _energy_points(INIT_ENERGY_POINTS), _attack_dmg(INIT_ATTACK_DMG)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name) : _name(name),
	_hit_points(INIT_HIT_POINTS), _energy_points(INIT_ENERGY_POINTS), _attack_dmg(INIT_ATTACK_DMG)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;	
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points,
		unsigned int energy_points, unsigned int attack_dmg) : _name(name),
	_hit_points(hit_points), _energy_points(energy_points), _attack_dmg(attack_dmg)
{
	std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& obj) : _name(obj.getName()),
	_hit_points(obj.getHitPoints()), _energy_points(obj.getEnergyPoints()),
	_attack_dmg(obj.getAttackDmg())
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_energy_points || !this->_hit_points)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attack_dmg
			<<" points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hit_points)
	{
		std::cout << this->_name << " is destroyed" << std::endl;
		return;
	}
	if (amount > this->_hit_points)
	{
		std::cout << this->_name << " took " << _hit_points << " damage" << std::endl;
		this->_hit_points = 0;
		return;
	}
	this->_hit_points -= amount;
	std::cout << this->_name << " took " << amount << " damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points || !this->_hit_points)
	{
		std::cout << this->_name << " can't be repaired" << std::endl;
		return;
	}
	if ((static_cast<unsigned long>(this->_hit_points)
		+ static_cast<unsigned long>(amount)) > std::numeric_limits<unsigned int>::max())
	{
		std::cout << "Repair amount attempt to overflow hit_points, aborting" << std::endl;
		return;
	}
	if (!amount || amount + this->_hit_points > INIT_HIT_POINTS)
	{
		std::cout << "Repair amount is invalid, aborting" << std::endl;
		return;
	}
	this->_energy_points--;
	this->_hit_points += amount;
	std::cout << this->_name << " was repaired by " << amount << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energy_points);
}

unsigned int ClapTrap::getAttackDmg() const
{
	return (this->_attack_dmg);
}

ClapTrap&	ClapTrap::operator= (const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->_name = obj.getName();
	this->_hit_points = obj.getHitPoints();
	this->_energy_points = obj.getEnergyPoints();
	this->_attack_dmg = obj.getAttackDmg();
	return (*this);
}