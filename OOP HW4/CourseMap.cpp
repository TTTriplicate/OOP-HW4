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
}

void CourseMap::addCourse(Course course) {
	//add Course to vector
	//sort by hash of coursetitle
	//throw error if exists/no load
}

std::shared_ptr<Course> CourseMap::getCourse(std::string title) {
	auto index = std::hash<std::string>{}(title);
	
	if (!loaded) {
		throw std::runtime_error("Error: Courses have not been loaded.  Exiting operation.");
	}
	else {	
		cursor = courses.begin() + courses.size() / 2;
		while (index <= std::hash<std::string>{}((*cursor)->getInfo(0))) {
			if (index == std::hash<std::string>{}((*cursor)->getInfo(0))) {	//Needs testing
				std::shared_ptr<Course> found = (*cursor);
				return found;
			}
		}
		throw std::invalid_argument("Error: Course not found");
	}
}

void CourseMap::deleteCourse(std::string title) {
	if (!loaded) {
		throw std::runtime_error("Error: Courses have not been loaded.  Exiting operation.");
	}
	auto search = std::hash<std::string>{}(title);
	for (cursor = courses.begin(); cursor < courses.end(); ++cursor) {
		if (search == std::hash<std::string>{}((*cursor)->getInfo(0))) {
			courses.erase(cursor);
		}
	}
}