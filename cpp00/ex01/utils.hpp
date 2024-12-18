/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:37:42 by amsaleh           #+#    #+#             */
/*   Updated: 2024/12/18 18:25:40 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <iostream>

bool	CheckInputErrors(bool bDisplay);
bool	CheckInputErrorsStr(std::string input);
bool	CheckPhoneNumber(std::string str);
bool	CheckSearchIndexInput(std::string str);
bool	CheckName(std::string str);
void	TruncateStr(std::string *str);

#endif