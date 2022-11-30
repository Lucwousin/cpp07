/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:17:30 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:17:30 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b) {
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template<typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

#endif