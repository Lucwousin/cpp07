/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 00:03:01 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 00:03:01 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

template<typename T>
class Array {
	public:
		Array();
		virtual ~Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array<T> &operator=(const Array<T> &rhs);

		T &operator[](unsigned int i) throw(std::exception);
		unsigned int size() const;

	private:
		T *_arr;
		unsigned int _size;
};

#include "Array.tpp"

#endif
