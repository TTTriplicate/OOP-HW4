#include "CourseMap.h"

CourseMap::CourseMap() {

}

CourseMap::~CourseMap() {
	courses.clear();
}

bool CourseMap::isLoaded() {
	return loaded;
}

void CourseMap::setLoadstate() {
	loaded = true;
}

void CourseMap::addCourse(std::shared_ptr<Course> course) {
	course->isGood();//throws a runtime error if it failed to construct; object will delete as it leaves scope during next course construction or when all construction ends
	auto index = course->getHash();
	for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {//check for duplicates, prevent adding it to vector
		if (index == (*cursor)->getHash()) {
			throw std::runtime_error(course->getInfo(0) + " already in list.");
		}
	}
	courses.push_back(course);
}

void CourseMap::sortCourses() {									//sorts by hashVal in approx. O(nlog(n))
	std::sort(courses.begin(), courses.end(), Course::compare);	//vs O(n^2) for previous insertion sort during add
}


std::shared_ptr<Course> CourseMap::getCourse(std::string title) {
	auto key = std::hash<std::string>{}(title);
		auto low = 0;
		auto high = courses.size();
		while (low < high) {
			auto index = courses.at(((low + high) / 2))->getHash();
			if (key == index) {
				cursor = courses.begin() + ((low + high) / 2);	//setting cursor allows deletion to use binary search
				return *cursor;
			}
			else if (key < index) {
				high = ((low + high) / 2);
			}
			else if (key > index) {
				low = ((low + high) / 2) + 1;
			}
		}
		throw std::invalid_argument("Course not found.");
}

void CourseMap::deleteCourse(std::string title) {
	getCourse(title);			//advances iterator or throws exception
	courses.erase(cursor);		//remove course at iterator from vector, delete object as shared_ptr leaves scope
}