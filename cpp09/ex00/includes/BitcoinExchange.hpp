/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:10:18 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/11 17:00:38 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <ctime>
#include <map>
#include <exception>
#include <string>

class BitcoinExchange
{
	private:
	enum	Issues
	{
		ERR_OPEN_FILE,
		ERR_HEADER,
		ERR_ENTRY_FORMAT,
		ERR_DATE_FORMAT,
		ERR_TIMESTAMP,
		ERR_BTC_AMOUNT,
		ERR_BTC_PRICE
	};
	std::map<time_t, double>	m_map;
	bool						m_bInit;
	std::size_t					line;
	const char*					file;
	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange& obj);
	~BitcoinExchange();
	void	InitMap();
	void	ParseFile(const char* file);
	void	IssueReporter(BitcoinExchange::Issues issue) const;
	static size_t	cleanLine(std::string& str);
	BitcoinExchange&	operator=(BitcoinExchange& obj);
	class	ParsingFailure: public std::exception
	{
		const char*	what() const throw();
	};
	class	MapAlreadyInitalized: public std::exception
	{
		const char*	what() const throw();
	};
};

#endif