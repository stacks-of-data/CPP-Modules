/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:50:05 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/03 17:27:25 by amsaleh          ###   ########.fr       */
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
	return (0);
}