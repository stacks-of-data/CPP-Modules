/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:31:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 19:45:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& obj);
	~ScavTrap();
	void	attack(const std::string& target);
	void	guardGate();
	ScavTrap&	operator= (ScavTrap& obj);
};

#endif