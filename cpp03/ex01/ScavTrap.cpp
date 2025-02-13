/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:36:22 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 19:46:48 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap::ClapTrap(DEFAULT_TRAP_NAME, 100, 50, 20)
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 50, 20)
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
	std::cout << "ScavTrap Destructor constructor called" << std::endl;
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
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_dmg = obj.attack_dmg;
	return (*this);
}