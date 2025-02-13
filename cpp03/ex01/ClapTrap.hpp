/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:49:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 18:37:18 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP
#define DEFAULT_TRAP_NAME "DEFAULT_NAME"

#include <iostream>

class ClapTrap
{
	protected:
	std::string	name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_dmg;
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hit_points,
		unsigned int energy_points, unsigned int attack_dmg);
	ClapTrap(ClapTrap& obj);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	std::string	getName();
	unsigned int	getHitPoints();
	unsigned int	getEnergyPoints();
	unsigned int	getAttackDmg();
	ClapTrap&	operator= (const ClapTrap& obj);
};

#endif