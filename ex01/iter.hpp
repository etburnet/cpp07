/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:49:39 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/24 13:55:04 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

template <typename T>
void iter(T *array, int length, void (*f)(T const&))
{
	if (array == NULL)
	{
		std::cout << "Array is NULL" << std::endl;
		return ;
	}
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void ft_add(T const &i)
{
	std::cout << i << std::endl;
}