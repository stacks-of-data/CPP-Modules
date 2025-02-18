/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:26:15 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 16:10:06 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Air.hpp"
#include "MateriaSource.hpp"

int main()
{
	AMateria* tmp;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Air());
	src->learnMateria(new Fire());
	tmp = new Fire();
	src->learnMateria(tmp);
	delete tmp;
	ICharacter* player = new Character("MrGamer");
	tmp = src->createMateria("ice");
	player->equip(tmp);
	tmp = src->createMateria("cure");
	player->equip(tmp);
	tmp = src->createMateria("fire");
	player->equip(tmp);
	tmp = src->createMateria("air");
	player->equip(tmp);
	ICharacter* enemy = new Character("enemy");
	player->use(0, *enemy);
	player->use(1, *enemy);
	player->use(2, *enemy);
	player->use(3, *enemy);
	delete enemy;
	delete player;
	delete src;
	return 0;
}