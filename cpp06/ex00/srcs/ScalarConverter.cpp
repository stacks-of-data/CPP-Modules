/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:05:26 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 00:47:55 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return (*this);
}

static bool	checkIfDigit(char c)
{
	if (c < 0x30 || c > 0x39)
		return (false);
	return (true);
}

static char	checkDatatype(const std::string& str, const size_t len)
{
	size_t pos = 0;
	size_t lenS1 = len - 1;
	char lvl = DATATYPE_INT;
	while (pos < len)
	{
		if (pos == 0 && (str[pos] == '+' || str[pos] == '-'))
			pos++;
		else
		{
			if (str[pos] == 'f' && pos == lenS1)
				return (DATATYPE_FLOAT);
			if (str[pos] == '.' && lvl == DATATYPE_INT)
				lvl = DATATYPE_DOUBLE;
			else if (!checkIfDigit(str[pos]))
				return (DATATYPE_UNKNOWN);
			pos++;
		}
	}
	return (lvl);
}

static bool	checkIfScientific(const std::string& str)
{
	size_t pos = 0;
	if (str[0] == '+' || str[0] == '-')
		pos++;
	if (!str.compare(pos, std::string::npos, "inf") || !str.compare(pos, std::string::npos, "nan"))
		return (true);
	return (false);
}

static char	getDatatype(const std::string& str)
{
	if (str.length() == 0)
		return (DATATYPE_UNKNOWN);
	if (str.length() == 1)
	{
		if (checkIfDigit(str[0]))
			return (DATATYPE_INT);
		return (DATATYPE_CHAR);
	}
	if (checkIfScientific(str))
		return (DATATYPE_SCIENTIFIC);
	char lvl = checkDatatype(str, str.length());
	if (lvl == DATATYPE_UNKNOWN)
		return (DATATYPE_UNKNOWN);
	if (lvl == DATATYPE_INT)
	{
		size_t target = 10;
		if (str[0] == '+' || str[0] == '-')
			target++;
		if (str.length() <= target)
		{
			long lVal = atol(str.c_str());
			if (lVal <= std::numeric_limits<int>::max() && lVal >= std::numeric_limits<int>::min())
				return (DATATYPE_INT);
		}
	}
	if (lvl == DATATYPE_FLOAT)
	{
		float fVal = strtof(str.c_str(), NULL);
		if (fVal != HUGE_VAL && fVal != -HUGE_VAL)
			return (DATATYPE_FLOAT);
	}
	if (lvl == DATATYPE_DOUBLE || lvl == DATATYPE_INT)
	{
		double dVal = strtod(str.c_str(), NULL);
		if (dVal != HUGE_VAL_F64 && dVal != -HUGE_VAL_F64)
			return (DATATYPE_DOUBLE);
	}
	return (DATATYPE_UNKNOWN);
}

static void	writeCharOutput(const TScalarData& data, const TScalarModes& modes)
{
	std::stringstream	ss;
	std::string			sOut;

	ss.exceptions(std::stringstream::failbit | std::stringstream::badbit);
	if (modes.cMode == MODE_IMPOSSIBLE)
		sOut = "Impossible";
	else if (modes.cMode == MODE_UNDISPLAYABLE)
		sOut = "Non displayable";
	else
	{
		ss << '\'' << data.cVal << '\'';
		ss >> sOut;
	}
	std::cout << "char: " << sOut << '\n';
}

static void	writeIntOutput(const TScalarData& data, const TScalarModes& modes)
{
	std::stringstream	ss;
	std::string			sOut;

	ss.exceptions(std::stringstream::failbit | std::stringstream::badbit);
	if (modes.iMode == MODE_IMPOSSIBLE)
		sOut = "Impossible";
	else
	{
		ss << data.iVal;
		ss >> sOut;
	}
	std::cout << "int: " << sOut << '\n';
}

static void	writeFloatOutput(const std::string& str, const TScalarData& data, const TScalarModes& modes)
{
	std::stringstream	ss;
	std::string			sOut;
	int					mode = -1;

	ss.exceptions(std::stringstream::failbit | std::stringstream::badbit);
	if (modes.fMode != MODE_SCIENTIFIC)
	{
		if (modes.fMode == MODE_IMPOSSIBLE)
			sOut = "Impossible";
		else
		{
			ss << data.fVal;
			ss >> sOut;
			mode = 0;
			if (sOut.find('.') != std::string::npos)
				mode = 1;
		}
		if (mode == 1)
			std::cout << "float: " << sOut << "f\n";
		else if (mode == 0)
			std::cout << "float: " << sOut << ".0f\n";
		else
			std::cout << "float: " << sOut << '\n';
	}
	else
	{
		char sign = 0;
		size_t pos = 0;
		if (str[0] == '-' || str[0] == '+')
		{
			if (str[0] == '-')
				sign = 1;
			pos++;
		}
		if (str[pos] == 'i')
			sOut = "inff";
		else
			sOut = "nanf";
		if (sign)
			sOut.insert(0, 1, '-');
		else
			sOut.insert(0, 1, '+');
		std::cout << "float: " << sOut << '\n';
	}
}

static void	writeDoubleOutput(const std::string& str, const TScalarData& data, const TScalarModes& modes)
{
	std::stringstream	ss;
	std::string			sOut;
	int					mode = -1;

	ss.exceptions(std::stringstream::failbit | std::stringstream::badbit);
	if (modes.dMode != MODE_SCIENTIFIC)
	{
		if (modes.dMode == MODE_IMPOSSIBLE)
			sOut = "Impossible";
		else
		{
			ss << data.dVal;
			ss >> sOut;
			mode = 0;
			if (sOut.find('.') != std::string::npos)
				mode = 1;
		}
		if (mode)
			std::cout << "double: " << sOut << "\n";
		else
			std::cout << "double: " << sOut << ".0\n";
	}
	else
	{
		char sign = 0;
		size_t pos = 0;
		if (str[0] == '-' || str[0] == '+')
		{
			if (str[0] == '-')
				sign = 1;
			pos++;
		}
		if (str[pos] == 'i')
			sOut = "inf";
		else
			sOut = "nan";
		if (sign)
			sOut.insert(0, 1, '-');
		else
			sOut.insert(0, 1, '+');
		std::cout << "double: " << sOut << '\n';
	}
}

static void	writeOutput(const std::string& str, const TScalarData& data, const TScalarModes& modes)
{
	writeCharOutput(data, modes);
	writeIntOutput(data, modes);
	writeFloatOutput(str, data, modes);
	writeDoubleOutput(str, data, modes);
}

static bool	isDisplayable(char c)
{
	if (c < 0x21 || c > 0x7E)
		return (false);
	return (true);
}

static void	intScalarConvert(const std::string& str, TScalarData& data, TScalarModes& modes)
{
	data.iVal = atoi(str.c_str());
	data.cVal = data.iVal;
	if ((int)data.cVal != data.iVal)
		modes.cMode = MODE_IMPOSSIBLE;
	else if (!isDisplayable(data.cVal))
		modes.cMode = MODE_UNDISPLAYABLE;
	data.fVal = data.iVal;
	if ((int)data.fVal != data.iVal)
		modes.fMode = MODE_IMPOSSIBLE;
	data.dVal = data.iVal;
	if ((int)data.dVal != data.iVal)
		modes.dMode = MODE_IMPOSSIBLE;
}

static void	floatScalarConvert(const std::string& str, TScalarData& data, TScalarModes& modes)
{
	data.fVal = atof(str.c_str());
	data.cVal = data.fVal;
	if ((float)data.cVal != data.fVal)
		modes.cMode = MODE_IMPOSSIBLE;
	else if (!isDisplayable(data.cVal))
		modes.cMode = MODE_UNDISPLAYABLE;
	data.iVal = data.fVal;
	if ((float)data.iVal != data.fVal)
		modes.iMode = MODE_IMPOSSIBLE;
	data.dVal = data.iVal;
	if ((float)data.dVal != data.fVal)
		modes.dMode = MODE_IMPOSSIBLE;
}

static void	doubleScalarConvert(const std::string& str, TScalarData& data, TScalarModes& modes)
{
	data.dVal = atof(str.c_str());
	data.cVal = data.dVal;
	if ((double)data.cVal != data.dVal)
		modes.cMode = MODE_IMPOSSIBLE;
	else if (!isDisplayable(data.cVal))
		modes.cMode = MODE_UNDISPLAYABLE;
	data.iVal = data.dVal;
	if ((double)data.iVal != data.dVal)
		modes.iMode = MODE_IMPOSSIBLE;
	data.fVal = data.dVal;
	if ((double)data.fVal != data.dVal)
		modes.fMode = MODE_IMPOSSIBLE;
}

static void	scientificScalarConvert(const std::string& str, TScalarData& data, TScalarModes& modes)
{
	modes.cMode = MODE_IMPOSSIBLE;
	modes.iMode = MODE_IMPOSSIBLE;
	data.fVal = atof(str.c_str());
	data.dVal = data.fVal;
	modes.fMode = MODE_SCIENTIFIC;
	modes.dMode = MODE_SCIENTIFIC;
}

void	ScalarConverter::convert(const std::string& str)
{
	char			cDatatype;
	TScalarData		data;
	TScalarModes	modes = {0, 0, 0, 0};
	cDatatype = getDatatype(str);
	switch (cDatatype)
	{
		case DATATYPE_CHAR:
			data.cVal = str[0];
			if (data.cVal < 0)
				modes.cMode = MODE_UNDISPLAYABLE;
			data.iVal = data.cVal;
			data.fVal = data.cVal;
			data.dVal = data.cVal;
			break;
		case DATATYPE_INT:
			intScalarConvert(str, data, modes);
			break;
		case DATATYPE_FLOAT:
			floatScalarConvert(str, data, modes);
			break;
		case DATATYPE_DOUBLE:
			doubleScalarConvert(str, data, modes);
			break;
		case DATATYPE_SCIENTIFIC:
			scientificScalarConvert(str, data, modes);
			break;
		case DATATYPE_UNKNOWN:
			modes.cMode = MODE_IMPOSSIBLE;
			modes.iMode = MODE_IMPOSSIBLE;
			modes.fMode = MODE_IMPOSSIBLE;
			modes.dMode = MODE_IMPOSSIBLE;
			break;
	}
	writeOutput(str, data, modes);
}