/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:36:22 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 23:42:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap(DEFAULT_TRAP_NAME, INIT_HIT_POINTS, INIT_ENERGY_POINTS, INIT_ATTACK_DMG)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name, INIT_HIT_POINTS, INIT_ENERGY_POINTS, INIT_ATTACK_DMG)
{
	std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& obj) : ClapTrap::ClapTrap(obj.getName(), obj.getHitPoints(),
	obj.getEnergyPoints(), obj.getAttackDmg())
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->energy_points || !this->hit_points)
	{
		std::cout << "ScavTrap " << this->name << " can't attack" << std::endl;
		return;
	}
	this->energy_points--;
	std::cout << "ScavTrap " << this->name << " attacks "
		<< target << ", causing " << this->attack_dmg
			<<" points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->name << " is now in gate keeper mode" << std::endl;
}

ScavTrap&	ScavTrap::operator= (ScavTrap& obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_dmg = obj.getAttackDmg();
	return (*this);
}