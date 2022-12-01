/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 00:03:04 by lsinke        #+#    #+#                 */
/*   Updated: 2022/12/01 00:03:04 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

static void testInt() {
	Array<int> arr(100);
	for (int i = 0; i < 100; i++)
		arr[i] = i + 1;
	for (int i = 0; i < 100; i++)
		std::cout << arr[i] << '\t';
	std::cout << '\n';
}

static void testAssignCopy() {
	Array<int> a(10);
	for (int i = 0; i < 10; i++)
		a[i] = i;
	{
		Array<int> b(a);
		for (int i = 0; i < 10; i++)
			b[i]++;
		for (int i = 0; i < 10; i++)
			if (a[i] != i || b[i] != i + 1)
				std::cerr << "Something went wrong, a[" << i << "] == " << a[i] << "; should be " << i << "\n"
						  << "b[" << i << "] == " << b[i] << "; should be " << i + 1 << "\n";
		a = b;
	}
	for (int i = 0; i < 10; i++)
		if (a[i] != i + 1)
			std::cerr << "Something went wrong, a[" << i << "] == " << a[i] << "; should be " << i + 1 << "\n";
}

static void testOOB() {
	Array<void *> arr;

	try {
		arr[0];
	} catch (std::exception &err) {
		std::cout << "Caught OOB\n";
	}
}

int main() {
	testInt();
	testAssignCopy();
	testOOB();
}