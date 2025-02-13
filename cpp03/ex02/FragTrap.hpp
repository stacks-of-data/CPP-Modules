/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:49:41 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 23:08:37 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	static const unsigned int	INIT_HIT_POINTS = 100;
	static const unsigned int	INIT_ENERGY_POINTS = 100;
	static const unsigned int	INIT_ATTACK_DMG = 30;
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap& obj);
	~FragTrap();
	void	attack(const std::string& target);
	void	highFivesGuys(void);
	FragTrap&	operator= (FragTrap& obj);
};

#endif