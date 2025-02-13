/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:49:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 19:12:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
	std::string	name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_dmg;
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& obj);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	std::string	getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergyPoints() const;
	unsigned int	getAttackDmg() const;
	ClapTrap&	operator= (const ClapTrap& obj);
};

#endif