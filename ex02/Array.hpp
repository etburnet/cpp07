/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:28:52 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/09 11:45:50 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stddef.h>

template <class T>
class Array
{
	private:
		T* array;
		unsigned int _size;
	public:
		Array();
		Array(const Array &);
		Array &operator=(const Array &);
		Array(unsigned int n);
		unsigned int size() const;
		T& operator[](int i);
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
	this->array = NULL;
}

template <typename T>
Array<T>::~Array()
{
	delete this->array;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n]();
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
	int i = 0;
	int j = 0;
	
	if (this == &other)
		return (*this);
	while (other.array[i])
		i++;
	this->array = *new T[i];
	while (j < i)
		this->array[j] = other.array[j++];
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template<typename T>
T& Array<T>::operator[](int i)
{
    if (i < 0 || static_cast<unsigned int>(i) >= _size)
        throw IndexOutOfBounds();
    return array[i];
}