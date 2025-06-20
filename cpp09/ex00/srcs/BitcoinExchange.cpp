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
#include <sstream>

void  BitcoinExchange::SplitTokens(std::string& str, std::string* toks, char delim)
{
    std::stringstream   ss(str);

    ss.exceptions(std::stringstream::badbit);
    toks[0].clear();
    toks[1].clear();
    size_t i = 0;
    while (std::getline(ss, toks[i], delim))
    {
        size_t j = 0;
        while (std::isspace(toks[i][j]))
            j++;
        toks[i].erase(0, j);
        j = 0;
        while (toks[i][j] && !std::isspace(toks[i][j]))
            j++;
        toks[i].erase(j, std::string::npos);
        if (i == 1)
            return;
        i++;
    }
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
			std::cerr << "Bitcoin amount is invalid";
			break;
		case ERR_BTC_PRICE:
			std::cerr << "line:" << line << '\n';
			std::cerr << "Bitcoin price is invalid";
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

double  ParseDouble(const char* str)
{
    std::stringstream ss(str);
    double val;

    ss.exceptions(std::stringstream::badbit);
    ss >> val;
    if (ss.fail())
        return (HUGE_VAL_F64);
    char tmp;
    if (ss >> tmp)
        return (HUGE_VAL_F64);
    return (val);
}

std::pair<time_t, double> BitcoinExchange::ParseLine(std::string& sLine,
    std::string *toks, char delim) const
{
    std::pair<time_t, double>   data;
    std::tm			            t_data = {};
    
    SplitTokens(sLine, toks, delim);
	if (toks[0].empty() || toks[1].empty())
	{
		IssueReporter(ERR_ENTRY_FORMAT);
		throw BitcoinExchange::ParsingFailure();
	}
	if (!strptime(toks[0].c_str(), "%Y-%m-%d", &t_data))
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
    data.second = ParseDouble(toks[1].c_str());
	if (data.second == HUGE_VAL_F64 || data.second < 0)
	{
		IssueReporter(ERR_BTC_PRICE);
		throw BitcoinExchange::ParsingFailure();
	}
    if (delim == '|' && data.second > 1000)
    {
        IssueReporter(ERR_BTC_PRICE);
		throw BitcoinExchange::ParsingFailure();
    }
    return (data);
}

void    BitcoinExchange::ValidateHeader(std::string& sLine, char delim) const
{
    std::stringstream   ss(sLine);
    std::string         tok;
    size_t              i = 0;

    ss.exceptions(std::stringstream::badbit);
    while (std::getline(ss, tok, delim))
    {
        size_t j = 0;
        while (std::isspace(tok[j]))
            j++;
        if (!tok[j] || i == 2)
        {
            IssueReporter(ERR_HEADER);
		    throw BitcoinExchange::ParsingFailure();
        }
        i++;
    }
    if (i < 2)
    {
        IssueReporter(ERR_HEADER);
		throw BitcoinExchange::ParsingFailure();
    }
}

void	BitcoinExchange::ParseFile(const char* file)
{
	std::ifstream	            fs(file);
	std::string		            sLine;
    std::string                 toks[2];
    std::pair<time_t, double>   data;

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
				ValidateHeader(sLine, '|');
			else if (!sLine.empty())
			{
                try
                {
                    data = ParseLine(sLine, toks, '|');
                }
                catch (...)
                {
                    continue;
                }
				std::map<time_t, double>::const_iterator it = this->m_map.lower_bound(data.first);
				if (it == this->m_map.end())
					--it;
				std::cout << toks[0] << " => " << toks[1] << " = " << (*it).second * data.second << std::endl;
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
    std::string                     toks[2];
	std::pair<time_t, double>		data;

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
                ValidateHeader(sLine, ',');
			else if (!sLine.empty())
			{
                data = ParseLine(sLine, toks, ',');
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