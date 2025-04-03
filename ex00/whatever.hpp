/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:04:28 by eburnet           #+#    #+#             */
/*   Updated: 2025/04/02 13:44:43 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

template <typename type>
inline const type &min(const type &a, const type &b)
{
	return a < b ? a : b;
}

template <typename type>
inline const type &max(const type &a, const type &b)
{
	return a > b ? a : b;
}

template <typename type>
void swap(type &a, type &b)
{
	type tmp = a;
	a = b;
	b = tmp;
}

#endif