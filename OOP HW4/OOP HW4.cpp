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
				std::shared_ptr<Course> gotten = map.getCourse(input);
				for (int i = 0; i < 6; ++i) {
					std::cout << gotten->getInfo(i) << std::endl;
				}
			}
			else if (input[0] == 'D') {
				std::cout << "Which course would you like to remove:" << std::endl;
				getline(std::cin, input);
				map.deleteCourse(input);
				std::cout << input << " removed from the course list." << std::endl;
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
		catch (std::fstream::failure & e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}

