/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:49:41 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/13 19:56:19 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap& obj);
	~FragTrap();
	void	attack(const std::string& target);
	void	highFivesGuys(void);
	FragTrap&	operator= (FragTrap& obj);
};

#endif