/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:49:39 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/03 13:13:15 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

template <typename T>
void iter(T *array, int length, void (*f)(T const&))
{
	int array_len = 0;
	while (array[array_len])
		array_len++;	
	if (!array || length > array_len)
		return ;
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void ft_add(T const &i)
{
	std::cout << i << std::endl;
}