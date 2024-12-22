/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:39:52 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/22 21:34:36 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	this->weapon_type = weapon_type;
}

Weapon::~Weapon()
{
}

const std::string	Weapon::getType()
{
	return (weapon_type);
}

void	Weapon::setType(std::string new_weapon_type)
{
	weapon_type = new_weapon_type;
}