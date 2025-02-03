/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:50:05 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/03 15:57:36 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdio>

int main()
{
	Zombie*	zombie = new Zombie("Brainz");
	zombie->announce();
	delete zombie;
	zombie = newZombie("Brainz_newZombie");
	zombie->announce();
	delete zombie;
	randomChump("Brainz_randomChump");
	for (int i = 1; i < 51; i++)
	{
		std::string z_name = "";
		char	res[30];
		if (std::sprintf(res, "Brainz_randomChump%d", i) == -1)
		{
			std::cerr << "An error occured in sprintf\n";
			return (1);
		}
		z_name.append(res);
		randomChump(z_name);
	}
	return (0);
}