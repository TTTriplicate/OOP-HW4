#include "Course.h"

Course::Course() {}

Course::Course(std::string info[]) {
	for (unsigned i = 0; i < 6; ++i) {
		data[i] = info[i];
	}
	hashVal = std::hash<std::string>{}(data[0]);
	if (hashVal == std::hash<std::string>{}("")) {
		good = false;
	}
}

Course::~Course() {}

void Course::isGood() {
	if (!good) {
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
		throw std::invalid_argument("Error: index out of range in Course data.");//catch indicies that are out of range
	}
}

bool Course::compare(std::shared_ptr<Course> l, std::shared_ptr<Course> r) {//for sorting with built-in std::sort
	l->isGood();
	r->isGood();
	return l->hashVal < r->hashVal;											//can't just overload operator< due to
}																			//use of shared_ptrs
