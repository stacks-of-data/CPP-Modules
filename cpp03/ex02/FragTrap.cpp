/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:51:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:35:11 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap::ClapTrap(DEFAULT_TRAP_NAME, INIT_HIT_POINTS, INIT_ENERGY_POINTS, INIT_ATTACK_DMG)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap::ClapTrap(name, INIT_HIT_POINTS, INIT_ENERGY_POINTS, INIT_ATTACK_DMG)
{
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap::ClapTrap(obj.getName(), obj.getHitPoints(),
	obj.getEnergyPoints(), obj.getAttackDmg())
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->_energy_points || !this->_hit_points)
	{
		std::cout << "FragTrap " << this->_name << " can't attack" << std::endl;
		return;
	}
	this->_energy_points--;
	std::cout << "FragTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attack_dmg
			<<" points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << this->_name << ": HIGH FIVE!!!" << std::endl;
}

FragTrap&	FragTrap::operator= (const FragTrap& obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->_name = obj.getName();
	this->_hit_points = obj.getHitPoints();
	this->_energy_points = obj.getEnergyPoints();
	this->_attack_dmg = obj.getAttackDmg();
	return (*this);
}