/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:28:52 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:28:52 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template<typename T>
void iter(T *ptr, size_t len, void (*f)(T &)) {
	for (size_t i = 0; i < len; i++)
		f(ptr[i]);
}

template<typename T>
void print(T &ref) {
	std::cout << ref << '\t';
}

// Instantiation of function template - it compiled without doing this but subject explicitly mentions this
template void print<const std::string>(const std::string &ref);
template void print<const int>(const int &ref);
template void print<const char>(const char &ref);

#endif
