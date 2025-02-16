/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:44:13 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/16 21:18:00 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	printIdeas(Brain *brain)
{
	std::string	idea;
	for (int i = 0; i < 100; i++)
	{
		idea = brain->getIdea(i);
		for (int i = 0; i < 100; i++)
		{
			if (!idea.empty())
				std::cout << "idea " << i << ": " << idea << std::endl;
			idea.clear();
		}
	}
}

int main()
{
	Animal	*animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	std::cout << "Deep copy tests section:" << std::endl;
	std::cout << "Dogs:" << std::endl;
	Dog	*dog_x = new Dog();
	Brain	*brain_dog_x = new Brain();
	brain_dog_x->setIdea(10, "FOOD!!");
	brain_dog_x->setIdea(20, "SLEEP!!");
	brain_dog_x->setIdea(30, "PLAY!!");
	dog_x->setBrain(*brain_dog_x);
	Dog *dog_y = new Dog(*dog_x);
	brain_dog_x->setIdea(40, "IDEA!!");
	dog_x->setBrain(*brain_dog_x);
	Brain	*brain_dog_y = new Brain(dog_y->getBrain());

	std::cout << "dog_x ideas preview:" << std::endl;
	printIdeas(brain_dog_x);
	std::cout << "dog_y ideas preview:" << std::endl;
	printIdeas(brain_dog_y);

	delete brain_dog_x;
	delete brain_dog_y;
	delete dog_x;
	delete dog_y;

	std::cout << "Cats:" << std::endl;
	Cat	*cat_x = new Cat();
	Brain	*brain_cat_x = new Brain();
	brain_cat_x->setIdea(10, "Meow!!");
	brain_cat_x->setIdea(20, "Meow!!");
	brain_cat_x->setIdea(30, "MEOW!!");
	cat_x->setBrain(*brain_cat_x);
	Cat *cat_y = new Cat(*cat_x);
	brain_cat_x->setIdea(40, "FOOOOOOD!!");
	cat_x->setBrain(*brain_cat_x);
	Brain	*brain_cat_y = new Brain(cat_y->getBrain());
	
	std::cout << "cat_x ideas preview:" << std::endl;
	printIdeas(brain_cat_x);
	std::cout << "cat_y ideas preview:" << std::endl;
	printIdeas(brain_cat_y);

	delete brain_cat_x;
	delete brain_cat_y;
	delete cat_x;
	delete cat_y;

	for (int i = 10; i > 0; i--)
		delete animals[i - 1];
}