/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:59:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 23:48:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(std::string(DEFAULT_TRAP_NAME).append("_clap_name"),
	FragTrap::INIT_HIT_POINTS, ScavTrap::INIT_ENERGY_POINTS, FragTrap::INIT_ATTACK_DMG), name(DEFAULT_TRAP_NAME)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(std::string(name).append("_clap_name"),
	FragTrap::INIT_HIT_POINTS, ScavTrap::INIT_ENERGY_POINTS, FragTrap::INIT_ATTACK_DMG), name(name)
{
	std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& obj) : ClapTrap(obj.getName(),
	obj.getHitPoints(),obj.getEnergyPoints(), obj.getAttackDmg()), ScavTrap(obj.getName()),
	FragTrap(obj.getName()), name(obj.getName())
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "whoAmI: " << this->name << ' ' << this->ClapTrap::name << std::endl;
}

DiamondTrap&	DiamondTrap::operator= (const DiamondTrap& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->ClapTrap::name = std::string(name).append("_clap_name");
	this->name = name;
	this->hit_points = obj.getHitPoints();
	this->energy_points = obj.getEnergyPoints();
	this->attack_dmg = obj.getAttackDmg();
	return (*this);
}