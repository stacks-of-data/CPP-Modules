/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:47:51 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/14 22:58:35 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	diamond_obj("ULTIMATE_TRAP");
	diamond_obj.whoAmI();
	for (int i = 0; i < 40; i++)
		diamond_obj.attack("Alien");
	diamond_obj.whoAmI();
	diamond_obj.highFivesGuys();
	diamond_obj.guardGate();
	for (int i = 0; i < 11; i++)
		diamond_obj.attack("Alien");
}