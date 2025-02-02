/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:03:07 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/02 19:05:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
	std::string	name;
	Weapon*		weapon;
	public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon& weapon);
	void	attack();
};

#endif