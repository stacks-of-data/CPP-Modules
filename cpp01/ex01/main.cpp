/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:50:05 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/22 00:24:22 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	n_zombies = 500;
	std::string z_name = "Brainzzz";
	Zombie*	z_horde = zombieHorde(n_zombies, z_name);
	for (int i = 0; i < n_zombies; i++)
		z_horde[i].announce();
	delete[] z_horde;
	return (0);
}