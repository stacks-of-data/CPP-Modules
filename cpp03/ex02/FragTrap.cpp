/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:51:46 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 20:03:49 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap::ClapTrap(DEFAULT_TRAP_NAME, 100, 100, 30)
{
	std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap& obj) : ClapTrap::ClapTrap(obj.getName(), obj.getHitPoints(),
	obj.getEnergyPoints(), obj.getAttackDmg())
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor constructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->energy_points || !this->hit_points)
	{
		std::cout << "FragTrap " << this->name << " can't attack" << std::endl;
		return;
	}
	this->energy_points--;
	std::cout << "FragTrap " << this->name << " attacks "
		<< target << ", causing " << this->attack_dmg
			<<" points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->name << ": HIGH FIVE!!!" << std::endl;
}

FragTrap&	FragTrap::operator= (FragTrap& obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->name = obj.getName();
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_dmg = obj.getAttackDmg();
	return (*this);
}