/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:32:20 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/22 00:05:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string z_name)
{
	this->z_name = z_name;
}

Zombie::~Zombie()
{
	std::cout << z_name << " Destroyed!\n";
}

void	Zombie::setZombieName(std::string z_name)
{
	this->z_name = z_name;
}

void	Zombie::announce(void)
{
	std::cout << z_name << ": BraiiiiiiinnnzzzZ...\n";
}