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

#define MAX_VAL 750
static int provided_main()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

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

	provided_main();
}