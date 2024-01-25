#include "day2.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int MaxRed = 12;
const int MaxGreen = 13;
const int MaxBlue = 14;


int sum_of_possible_games() {
	std::fstream input;
	input.open("input2.txt");
	int sum = 0;
	

	if (input.is_open()) {
		std::string line;
		//std::string delimiter = ":";
		std::stringstream ss{};
		std::string game{};
		std::vector<std::string> games{};
		int n = 0;
		int num = 1;

		while (std::getline(input, line)) {
			int R = 0, G = 0, B = 0;
			// cut off "game number x: "
			std::string contents = line.substr(line.find(":")).substr(2);
			ss = std::stringstream(contents);


			std::cout << "\nGame " << num << ":\n";

			bool isPossible = false;
			// split on ";"
			while (std::getline(ss, game, ';')) {
				R=0, G=0, B = 0;
				std::stringstream single_game_ss = std::stringstream(game);
				std::string item{};

				while (!single_game_ss.eof()) {
					single_game_ss >> n;
					single_game_ss >> item;

					if (item[0] == 'r') {
						R += n;
					}
					else if (item[0] == 'g') {
						G += n;
					}
					else if (item[0] == 'b') {
						B += n;
					}
				}


				std::cout << "[R, G, B] : " << R << ", " << G << ", " << B << std::endl;
				if (R > MaxRed || G > MaxGreen || B > MaxBlue) {
					std::cout << "Round not possible" << std::endl;
					isPossible = false;
					break;
				}
				else {
					isPossible = true;
				}
			}


			if (isPossible) {
				sum += num;
			}

			std::cout << std::endl;
			
			num++;
		}
	}
	else {
		std::cout << "failed to open input2" << std::endl;
	}

	return sum;
}