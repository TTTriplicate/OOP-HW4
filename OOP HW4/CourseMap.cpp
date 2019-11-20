#include "CourseMap.h"

CourseMap::CourseMap() {

}

CourseMap::~CourseMap() {
	courses.clear();
}

void CourseMap::loadCourses(std::string path) {
	if (loaded) {
		throw std::runtime_error("Error: Courses already loaded.  Exiting operation.");
	}
	for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
		std::cout << (*cursor)->getInfo(0) << " " << (*cursor)->getHash() << std::endl;
	}
	loaded = true;
}

bool CourseMap::isLoaded() {
	return loaded;
}

void CourseMap::setLoadstate() {
	loaded = true;
}

void CourseMap::addCourse(std::shared_ptr<Course> course) {
	auto index = course->getHash();
	if (courses.size() == 0) {
		courses.push_back(course);
	}
	else {
		for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
			//std::cout << course < &cursor;
			if (index == (*cursor)->getHash()) {
				throw std::runtime_error(course->getInfo(0) + " already in list.");
			}
			if (cursor == courses.end()-1) {
				courses.push_back(course);
				break;
			}
		}
	}
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
		//size_t low = 0;
		//size_t high = courses.size();
		//while (low < high){
		//	auto toCheck = courses.at(low + high/2)->getHash();
		//	if (toCheck == index) {
		//		return courses.at(high / low);
		//	}
		//	else if (toCheck > index) {
		//		high = low+high/2;
		//	}
		//	else if (toCheck < index) {
		//		low = low + high / 2;
		//	}
		//}

		for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
			auto current = (*cursor)->getHash();
			if (index == current) {
				return *cursor;
			}
			else if (index > current) {
				throw std::runtime_error("Course not found.");
			}
		}
	}
}

void CourseMap::deleteCourse(std::string title) {
	if (!loaded) {
		throw std::runtime_error("Error: Courses have not been loaded.  Exiting operation.");
	}
	auto search = std::hash<std::string>{}(title);
	for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
		if (search == (*cursor)->getHash()) {
			courses.erase(cursor);
			break;
		}
		else if (search > (*cursor)->getHash()) {
			throw std::invalid_argument("Error: course " + title + " not in list.");
		}
	}
}