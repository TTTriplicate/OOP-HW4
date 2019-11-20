#include "Course.h"

Course::Course() { std::cout << "Constructing " + data[0] << std::endl; }

Course::Course(std::string info[]) {
	std::cout << "Constructing overloaded " + info[0] << std::endl;
	for (auto i = 0; i < 6; ++i) {
		data[i] = info[i];
	}
	hashVal = std::hash<std::string>{}(data[0]);
}

Course::~Course() { std::cout << "deleting " + data[0] << std::endl; }

const std::size_t Course::getHash() const {
	return hashVal;
}

std::string Course::getInfo(int index) {
	if (index >= 0 && index < 6) {
		return data[index];
	}
	else {
		throw std::invalid_argument("Error: index out of range in Course data.");
	}
}

bool Course::compare(std::shared_ptr<Course> l, std::shared_ptr<Course> r) {
	return l->hashVal < r->hashVal;
}