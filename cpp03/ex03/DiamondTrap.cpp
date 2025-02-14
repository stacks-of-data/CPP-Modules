/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:59:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/14 22:56:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(std::string(DEFAULT_TRAP_NAME).append("_clap_name"),
	FragTrap::INIT_HIT_POINTS, ScavTrap::INIT_ENERGY_POINTS, FragTrap::INIT_ATTACK_DMG), _name(DEFAULT_TRAP_NAME)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(std::string(name).append("_clap_name"),
	FragTrap::INIT_HIT_POINTS, ScavTrap::INIT_ENERGY_POINTS, FragTrap::INIT_ATTACK_DMG), _name(name)
{
	std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj.getName(),
	obj.getHitPoints(),obj.getEnergyPoints(), obj.getAttackDmg()), ScavTrap(obj.getName()),
	FragTrap(obj.getName()), _name(obj.getName())
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "whoAmI: " << this->_name << ' ' << this->ClapTrap::_name << std::endl;
}

DiamondTrap&	DiamondTrap::operator= (const DiamondTrap& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->ClapTrap::_name = std::string(obj.getName()).append("_clap_name");
	this->_name = obj.getName();
	this->_hit_points = obj.getHitPoints();
	this->_energy_points = obj.getEnergyPoints();
	this->_attack_dmg = obj.getAttackDmg();
	return (*this);
}