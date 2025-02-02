/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:11:29 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/01 17:43:32 by amsaleh          ###   ########.fr       */
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
	int		n_contacts_init;
	int		GetNewContactIndex(void);
	public:
	PhoneBook(void);
	~PhoneBook();
	void	AddContact(void);
	void	SearchContacts(void);
};

#endif