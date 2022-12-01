/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.tpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 00:03:02 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 00:03:02 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <cstring>

template<typename T>
Array<T>::Array() {
	_size = 0;
	_arr = NULL;
}

template<typename T>
Array<T>::~Array() {
	if (_arr != NULL)
		delete[] _arr;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	_size = n;
	_arr = new T[_size]();
}

template<typename T>
Array<T>::Array(const Array<T> &other) {
	_size = 0;
	_arr = NULL;
	this->operator=(other);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this == &rhs)
		return *this;

	if (_size != rhs._size) {
		if (_arr != NULL)
			delete[] _arr;
		_size = rhs._size;
		_arr = new T[_size]();
	}
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = rhs._arr[i];
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int i) throw(std::exception) {
	if (i >= _size)
		throw std::exception();
	return _arr[i];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif