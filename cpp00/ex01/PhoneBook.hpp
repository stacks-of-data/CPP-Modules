/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:29 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 01:47:33 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

class	PhoneBook
{
	private:
	Contact	contacts[8];
	int		n_contacts_init = 0;
	int		GetNewContactIndex();
	public:
	void	AddContact();
};

#endif