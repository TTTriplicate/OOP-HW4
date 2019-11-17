#include "CourseMap.h"
#include <iostream>

int main()
{
	std::string input;
	std::string path = ".\\Homework 4 Data.txt";
	CourseMap map;
	while (true) {
		std::cout << "Choose an option: (L)oad courses, (G)et information on a course, (D)elete a course, or E(X)it:" << std::endl;
		getline(std::cin, input);
		try {
			input[0] = toupper(input[0]);
			if (input.length() > 1) {
				throw std::invalid_argument("Error: input too long.  Please enter L, G, D, or X");
			}
			else if (input[0] == 'X') {
				break;
			}
			else if (input[0] == 'L') {
				map.loadCourses(path);
			}
			else if (input[0] == 'G') {
				std::cout << "What course do you need information about:" << std::endl;
				getline(std::cin, input);
				map.getCourse(input);
			}
			else if (input[0] == 'D') {
				std::cout << "Which course would you like to remove:" << std::endl;
				getline(std::cin, input);
				map.deleteCourse(input);
			}
			else {
				throw std::invalid_argument("Error: " + input + " is not a valid command.  Please enter L, G, D, or X");
			}
		}
		catch (std::invalid_argument & i) {
			std::cerr << i.what() << std::endl;
		}
		catch (std::runtime_error & r) {
			std::cerr << r.what() << std::endl;
		}
	}

	return 0;
}

