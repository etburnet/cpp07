/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:28:52 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/25 10:48:28 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stddef.h>
#include <stdlib.h>

template <class T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(const Array &);
		Array &operator=(const Array &);
		Array(unsigned int n);
		unsigned int size() const;
		T& operator[](int i);
		const T& operator[](int i) const;
		~Array();
		class IndexOutOfBounds : public std::exception
		{
			public:
				const char* what() const throw() {
					return "Index is out of bounds !";
				}
		};
};

template <typename T>
Array<T>::Array()
{
	this->_array = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n]();
	this->_size = n;
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	operator=(other);
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
		return (*this);
	this->_size = other._size;
	this->_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = other._array[i];
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
T& Array<T>::operator[](int i)
{
	if (i < 0 || static_cast<unsigned int>(i) >= _size)
		throw IndexOutOfBounds();
	return this->_array[i];
}

template <typename T>
const T& Array<T>::operator[](int i) const
{
	if (i < 0 || static_cast<unsigned int>(i) >= _size)
		throw IndexOutOfBounds();
	return this->_array[i];
}