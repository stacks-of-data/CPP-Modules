/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:33:11 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/15 01:13:36 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
	std::string	ideas[100];
	public:
	Brain();
	Brain(const std::string *ideas_arr);
	Brain(const Brain& obj);
	~Brain();
	std::string	getIdea(const int index) const;
	void	setIdea(const int index, const std::string& sIdea);
	Brain&	operator= (const Brain& obj);
};

#endif