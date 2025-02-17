/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 00:26:15 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 02:00:56 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	ICharacter	*me = new Character("me");
	me->equip(new Ice());
	ICharacter	*lol = new Character("LOL");
	me->use(0, *lol);
	delete me;
	delete lol;
}