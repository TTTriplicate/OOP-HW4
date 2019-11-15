#include "Course.h"

Course::Course(){}

Course::Course(std::string info[]) {
	for (auto i = 0; i < 6; ++i) {
		data[i] = info[i];
	}
}

Course::~Course(){}

std::string Course::getInfo(int index) {
	if (index >= 0 && index < 6) {
		return data[index];
	}
	else {
		throw std::invalid_argument("Error: index out of range in Course data.");
	}
}