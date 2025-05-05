/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:57:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 02:47:03 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>

enum	ScalarDatatypes
{
	DATATYPE_CHAR,
	DATATYPE_INT,
	DATATYPE_FLOAT,
	DATATYPE_DOUBLE,
	DATATYPE_SCIENTIFIC,
	DATATYPE_UNKNOWN
};
enum	ScalarModes
{
	MODE_DEFAULT,
	MODE_UNDISPLAYABLE,
	MODE_SCIENTIFIC,
	MODE_IMPOSSIBLE
};
typedef struct SScalarData
{
	char	cVal;
	int		iVal;
	float	fVal;
	double	dVal;
}	TScalarData;
typedef struct SScalarModes
{
	char	cMode;
	char	iMode;
	char	fMode;
	char	dMode;
}	TScalarModes;

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter();
	ScalarConverter&	operator=(const ScalarConverter& obj);
	public:
	static void	convert(const std::string& str);
};

#endif