/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:26:00 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 23:44:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
	std::string name;
	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap& obj);
	~DiamondTrap();
	void	whoAmI();
	using	ScavTrap::attack;
	DiamondTrap&	operator= (const DiamondTrap& obj);
};

#endif