/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:38:31 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/06 18:11:34 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
	size_t	_size;
	T*		_arr;
	public:
	Array()
	{
		this->_arr = new T[0];
		this->_size = 0;
	}
	Array(const unsigned int n)
	{
		this->_arr = new T[n];
		this->_size = n;
	}
	Array(const Array& obj)
	{
		this->_arr = new T[obj.size()];
		this->_size = obj.size();
		for (size_t i = 0; i < obj.size(); i++)
			this->_arr[i] = obj[i];

	}
	~Array()
	{
		delete[] this->_arr;
	}
	size_t	size() const
	{
		return this->_size;
	}
	Array&	operator=(const Array& obj)
	{
		delete[] this->_arr;
		this->_arr = new T[obj.size()];
		this->_size = obj.size();
		for (size_t i = 0; i < obj.size(); i++)
			this->_arr[i] = obj[i];
		return (*this);
	}
	T&		operator[](const size_t i) const
	{
		if (i >= this->_size)
			throw std::exception();
		return (this->_arr[i]);
	}
};