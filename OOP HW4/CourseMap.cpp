#include "CourseMap.h"

CourseMap::CourseMap() {

}

CourseMap::~CourseMap() {
	courses.clear();
}

void CourseMap::loadCourses(std::string path) {
	//open file
	//read six lines and generate course
	//call addCourse
	//error if loaded/stream errors
	//loaded = true;
}

void CourseMap::addCourse(Course course) {
	//add Course to vector
	//sort by hash of coursetitle
	//throw error if exists/no load
}

std::shared_ptr<Course> CourseMap::getCourse(std::string title) {
	auto index = std::hash<std::string>{}(title);
	
	if (!loaded) {
		throw std::runtime_error("Course Map has not been loaded.  Exiting operation.");
	}
	else {	
		cursor = courses.begin() + courses.size() / 2;
		while (true) {
			if (index == std::hash<std::string>{}(cursor->getInfo(0))) {	//pretty sure I'm not using this right
				std::shared_ptr<Course> found(&*cursor);
				return found;
			}
			//else if (recursion) {
			//}
			else {
				throw std::invalid_argument("Error: Course not found");
			}
		}

	}
}

void CourseMap::deleteCourse(std::string title) {
	auto search = std::hash<std::string>{}(title);
	for (cursor = courses.begin(); cursor < courses.end(); ++cursor) {
		if (search == std::hash<std::string>{}(cursor->getInfo(0))) {
			courses.erase(cursor);
		}
	}
}