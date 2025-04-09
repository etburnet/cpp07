/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:18:04 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/09 11:46:09 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{	
	Array<int> a;
	Array<int> b(12);

	try
	{
		b[1] = 42;
		std::cout << b[1] << '\n';
		b[20];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}