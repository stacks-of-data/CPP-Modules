/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:49:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:34:31 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP
#define DEFAULT_TRAP_NAME "DEFAULT_NAME"

#include <iostream>

class ClapTrap
{
	protected:
	std::string	_name;
	unsigned int	_hit_points;
	unsigned int	_energy_points;
	unsigned int	_attack_dmg;
	public:
	static const unsigned int	INIT_HIT_POINTS = 10;
	static const unsigned int	INIT_ENERGY_POINTS = 10;
	static const unsigned int	INIT_ATTACK_DMG = 0;
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const std::string& name, const unsigned int hit_points,
		const unsigned int energy_points, const unsigned int attack_dmg);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(const unsigned int amount);
	void	beRepaired(const unsigned int amount);
	std::string	getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDmg() const;
	ClapTrap&	operator= (const ClapTrap& obj);
};

#endif