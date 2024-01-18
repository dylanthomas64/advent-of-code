#include "day1.h";
#include <fstream>;
#include <string>;
#include <iostream>


int day1() {
	std::ifstream input;
	input.open("input1.txt");


	if (input.is_open()) {
		std::string line{};
		int total = 0;
		int a = 0, b = 0;
		int line_number = 1;
		while (std::getline(input, line))
		{
			// iterate over line for first and last number
			std::string::const_iterator it = line.begin();

			// seek first number
			while (it != line.end()) {
				if (std::isdigit(*it)) {
					//'0' has ascii value 48 and numbers start from there
					a = int(*it) - int('0');

					// if there is only one number at the beginning this will cover that case as it will be skipped next while loop
					b = a;
					
					break;
				}
				++it;
			}

			// seek right hand number
			it = line.end();
			it--;
			while (it != line.begin()) {
				if (std::isdigit(*it)) {
					//'0' has ascii value 48 and numbers start from there
					b = *it - '0';
					break;
				}
				--it;
			}

			a *= 10;
			total += a + b;
			//std::cout << line_number << ": " << a << " + " << b << " = " << total << std::endl;
			line_number++;

		}
		return total;
	}
	return 0;
}