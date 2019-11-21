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
	for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
		std::cout << (*cursor)->getInfo(0) << " " << (*cursor)->getHash() << std::endl;
	}
	loaded = true;
}

void CourseMap::addCourse(std::shared_ptr<Course> course) {
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


std::shared_ptr<Course> CourseMap::getCourse(std::string title) {//make it binary search
	auto index = std::hash<std::string>{}(title);
	
	if (!loaded) {
		throw std::runtime_error("Error: Courses have not been loaded.  Exiting operation.");
	}
	else {
		size_t low = 0;
		size_t high = courses.size();
		while (low < high) {
			auto toCheck = courses.at(low + high / 2)->getHash();
			if (toCheck == index) {
				return courses.at(high / low);
			}
			else if (toCheck > index) {
				high = low + high / 2;
			}
			else if (toCheck < index) {
				low = low + high / 2;
			}
		}
	}

	//	for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {//iterative search
	//		auto current = (*cursor)->getHash();							//O(n) minus a little
	//		if (index == current) {
	//			return *cursor;
	//		}
	//		else if (index < current) {
	//			throw std::runtime_error("Course not found.");
	//		}
	//	}
	//}
}

void CourseMap::deleteCourse(std::string title) {
	getCourse(title);			//advances iterator or throws exception
	courses.erase(cursor);		//remove course at iterator from vector, delete object as shared_ptr leaves scope
}