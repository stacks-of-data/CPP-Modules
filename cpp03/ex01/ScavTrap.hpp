/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:31:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:34:37 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	static const unsigned int	INIT_HIT_POINTS = 100;
	static const unsigned int	INIT_ENERGY_POINTS = 50;
	static const unsigned int	INIT_ATTACK_DMG = 20;
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap();
	void	attack(const std::string& target);
	void	guardGate() const;
	ScavTrap&	operator= (const ScavTrap& obj);
};

#endif