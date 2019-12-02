#include "Course.h"

Course::Course() {}

Course::Course(std::string info[]) {
	for (unsigned i = 0; i < 6; ++i) {
		data[i] = info[i];
	}
	hashVal = std::hash<std::string>{}(data[0]);
	if (hashVal == std::hash<std::string>{}("")) {//makes sure it hasn't been fed an empty string array
		good = false;
	}
}

Course::~Course() {}

void Course::isGood() {//zombie check, called in CourseMap::addCourse()
	if (!good) {		//catches in main at loading loop
		throw std::runtime_error("Course failed to initialize.");
	}
}

std::size_t Course::getHash() {
	return hashVal;
}

std::string Course::getInfo(int index) {
	if (index >= 0 && index < 6) {
		return data[index];
	}
	else {
		throw std::invalid_argument("Error: index out of range in Course data.  Index must be between 0 and 5.");//catch indicies that are out of range
	}
}

bool Course::compare(std::shared_ptr<Course> l, std::shared_ptr<Course> r) {//for sorting with built-in std::sort
	return l->hashVal < r->hashVal;											//can't just overload operator< due to
}																			//use of shared_ptrs
