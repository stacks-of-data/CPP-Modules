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

#include <bits/types/time_t.h>
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
        ERR_DUPLICATE_DATE,
		ERR_BTC_AMOUNT,
		ERR_BTC_PRICE,
		ERR_MAP_UNINITALIZED,
		ERR_MAP_EMPTY
	};
    enum    DateModes
    {
        DATE_YEAR,
        DATE_MONTH,
        DATE_DAY,
        DATE_FINISH
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
    std::pair<time_t, double> ParseLine(std::string& sLine,
        std::string *toks, char delim) const;
    void    ValidateHeader(std::string& sLine, char delim) const;
	static void SplitTokens(std::string& str, std::string* toks, char delim);
    static time_t ParseDate(std::string& date);
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