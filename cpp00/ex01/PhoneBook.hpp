/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:29 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 10:59:17 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iomanip>
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
	void	SearchContacts();
};

#endif