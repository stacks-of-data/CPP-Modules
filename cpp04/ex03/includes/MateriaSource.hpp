/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:12:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/18 14:22:10 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
	std::string	types_arr[4];
	AMateria	*materia_arr[4];
	public:
	MateriaSource();
	MateriaSource(MateriaSource& obj);
	~MateriaSource();
	void	learnMateria(AMateria*);
	AMateria*	createMateria(std::string const& type);
	AMateria*	createMateria(const int& index);
	MateriaSource&	operator= (MateriaSource& obj);
};

#endif