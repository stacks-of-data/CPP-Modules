/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:37:42 by amsaleh           #+#    #+#             */
/*   Updated: 2025/02/02 19:06:28 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

bool	CheckInputErrors(bool bDisplay);
bool	CheckInputErrorsStr(std::string input);
bool	CheckPhoneNumber(std::string str);
bool	CheckSearchIndexInput(std::string str);
bool	CheckName(std::string str);
bool	CheckNickname(std::string str);
void	TruncateStr(std::string *str);

#endif