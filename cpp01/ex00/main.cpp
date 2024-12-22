/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:50:05 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/21 23:22:46 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*	zombie = new Zombie("Brainz");
	zombie->announce();
	delete zombie;
	zombie = newZombie("Brainz_newZombie");
	zombie->announce();
	delete zombie;
	randomChump("Brainz_randomChump");
	for (size_t i = 1; i < 51; i++)
	{
		std::string z_name = "Brainz_randomChump";
		z_name.append(std::to_string(i));
		randomChump(z_name);
	}
	return (0);
}