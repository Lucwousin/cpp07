/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 23:28:58 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/30 23:28:58 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	const std::string strings[] = {
		"one", "two", "three", "four", "five",
		"six", "seven", "eight", "nine", "ten",
		"eleven", "twelve", "thirteen", "fourteen", "fifteen",
		"sixteen", "seventeen", "eighteen", "nineteen", "twenty"
	};
	const int ints[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20
	};
	const char chars[] = {"This is a sentence!!"};

	iter(strings, 20, print);
	std::cout << "\n";
	iter(ints, 20, print);
	std::cout << "\n";
	iter(chars, 20, print);
	std::cout << "\n";
}
