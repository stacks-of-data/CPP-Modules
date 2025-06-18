/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:10:23 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/11 17:08:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

size_t	BitcoinExchange::cleanLine(std::string& str)
{
	std::size_t res;
	std::size_t i = 0;
	while (std::isspace(str[i]))
		i++;
	str.erase(0, i);
	while (str[i] && !std::isspace(str[i]))
		i++;
	if (std::isspace(str[i]))
	{
		std::size_t j = i;
		while (std::isspace(str[j]))
			j++;
		str.erase(i, j - i);
	}
	str[i] = 0;
	res = i + 1;
	std::size_t j = i + 1;
	i = j;
	while (std::isspace(str[i]))
		i++;
	str.erase(j, i - j);
	while (str[i] && !std::isspace(str[i]))
		i++;
	str.erase(i);
	return (res);
}

void	BitcoinExchange::IssueReporter(BitcoinExchange::Issues issue) const
{
	std::cerr << "\e[91m";
	switch (issue)
	{
		case ERR_OPEN_FILE:
			std::cerr << "Failed to open " << this->file;
			break;
		case ERR_HEADER:
			std::cerr << "Unexpected dataset header";
			break;
		case ERR_ENTRY_FORMAT:
			std::cerr << "line:" << this->line << '\n';
			std::cerr << "Incorrect entry format";
			break;
		case ERR_DATE_FORMAT:
			std::cerr << "line:" << this->line << '\n';
			std::cerr << "Incorrect date format";
			break;
		case ERR_TIMESTAMP:
			std::cerr << "line:" << this->line << '\n';
			std::cerr << "Date cannot be stored in std::time_t datatype";
			break;
		case ERR_BTC_AMOUNT:
			std::cerr << "line:" << this->line << '\n';
			std::cerr << "Bitcoin amount is out of range";
			break;
		case ERR_BTC_PRICE:
			std::cerr << "line:" << line << '\n';
			std::cerr << "Bitcoin price is out of range";
			break;
		case ERR_MAP_UNINITALIZED:
			std::cerr << "Map is uninitalized";
			break;
		case ERR_MAP_EMPTY:
			std::cerr << "Map is empty";
			break;
		default:
			std::cerr << "Unknown error";
	}
	std::cerr << "\e[39m" << std::endl;
}

void	BitcoinExchange::ParseFile(const char* file)
{
	std::ifstream	fs(file);
	std::string		sLine;
	std::tm			t_data = {};
	std::time_t		timestamp;
	double			btcAmount;

	if (this->m_bInit == false)
	{
		IssueReporter(ERR_MAP_UNINITALIZED);
		throw BitcoinExchange::ParsingFailure();
	}
	if (this->m_map.size() < 1)
	{
		IssueReporter(ERR_MAP_EMPTY);
		throw BitcoinExchange::ParsingFailure();
	}
	this->file = file;
	if (fs.is_open() == false)
	{
		IssueReporter(ERR_OPEN_FILE);
		throw BitcoinExchange::ParsingFailure();
	}
	fs.exceptions(std::ifstream::badbit);
	try
	{
		this->line = 0;
		while (std::getline(fs, sLine))
		{
			this->line++;
			if (this->line == 1)
			{
				std::size_t i = sLine.find('|');
				if (i == std::string::npos || sLine.find('|', i + 1) != std::string::npos)
				{
					IssueReporter(ERR_HEADER);
					throw BitcoinExchange::ParsingFailure();
				}
			}
			else if (!sLine.empty())
			{
				std::size_t i = sLine.find('|');
				if (i != std::string::npos)
					i = BitcoinExchange::cleanLine(sLine);
				else
				{
					IssueReporter(ERR_ENTRY_FORMAT);
					continue;
				}
				if (!strptime(sLine.c_str(), "%Y-%m-%d", &t_data))
				{
					IssueReporter(ERR_DATE_FORMAT);
					continue;
				}
				timestamp = std::mktime(&t_data);
				if (timestamp == -1)
				{
					IssueReporter(ERR_TIMESTAMP);
					continue;
				}
				btcAmount = strtod(sLine.c_str() + i, NULL);
				if (btcAmount < 0 || btcAmount > 1000)
				{
					IssueReporter(ERR_BTC_AMOUNT);
					continue;
				}
				std::map<time_t, double>::const_iterator it = this->m_map.lower_bound(timestamp);
				if (it == this->m_map.end())
					--it;
				std::cout << sLine.c_str() << " => " << sLine.c_str() + i << " = " << (*it).second * btcAmount << std::endl;
			}
		}
		fs.close();
	}
	catch (const std::exception& e)
	{
		fs.close();
		throw;
	}
}

void	BitcoinExchange::InitMap()
{
	if (this->m_bInit)
	{
		std::cerr << "Map already initalized" << std::endl;
		throw BitcoinExchange::MapAlreadyInitalized();
	}

	const char* filename = "data.csv";
	std::ifstream					fs(filename);
	std::string						sLine;
	std::pair<time_t, double>		data;
	std::tm							t_data = {};

	this->file = filename;
	if (fs.is_open() == false)
	{
		IssueReporter(ERR_OPEN_FILE);
		throw BitcoinExchange::ParsingFailure();
	}
	fs.exceptions(std::ifstream::badbit);
	try
	{
		this->line = 1;
		while (std::getline(fs, sLine))
		{
			if (this->line == 1)
			{
				std::size_t i = sLine.find(',');
				if (i == std::string::npos || sLine.find(',', i + 1) != std::string::npos)
				{
					IssueReporter(ERR_HEADER);
					throw BitcoinExchange::ParsingFailure();
				}
			}
			else if (!sLine.empty())
			{
				std::size_t i = sLine.find(',');
				if (i != std::string::npos)
					sLine.erase(i);
				else
				{
					IssueReporter(ERR_ENTRY_FORMAT);
					throw BitcoinExchange::ParsingFailure();
				}
				std::size_t j = sLine.find(',');
				if (j != std::string::npos)
					sLine.erase(j);
				if (!strptime(sLine.c_str(), "%Y-%m-%d", &t_data))
				{
					IssueReporter(ERR_DATE_FORMAT);
					throw BitcoinExchange::ParsingFailure();
				}
				data.first = std::mktime(&t_data);
				if (data.first == -1)
				{
					IssueReporter(ERR_TIMESTAMP);
					throw BitcoinExchange::ParsingFailure();
				}
				data.second = strtod(sLine.c_str() + i + 1, NULL);
				if (data.second == HUGE_VAL_F64 || data.second < 0)
				{
					IssueReporter(ERR_BTC_PRICE);
					throw BitcoinExchange::ParsingFailure();
				}
				this->m_map.insert(data);
			}
			this->line++;
		}
		fs.close();
		this->m_bInit = true;
	}
	catch (const std::exception& e)
	{
		this->m_map.clear();
		fs.close();
		throw;
	}
}

BitcoinExchange::BitcoinExchange(): m_bInit(false)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& obj): m_map(obj.m_map), m_bInit(obj.m_bInit)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange& obj)
{
	this->m_map = obj.m_map;
	this->m_bInit = obj.m_bInit;
	return (*this);
}

const char*	BitcoinExchange::ParsingFailure::what() const throw()
{
	return ("BitcoinExchange::ParsingFailure");
}

const char*	BitcoinExchange::MapAlreadyInitalized::what() const throw()
{
	return ("BitcoinExchange::MapAlreadyInitalized");
}