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
	else {
		std::fstream intake;
		std::string read[6];
		
		intake.open(path);
		if (intake) {
			while (!intake.eof()) {
				for (int i = 0; i < 6; ++i) {
					getline(intake, read[i]);
				}
				std::shared_ptr<Course> toAdd = std::shared_ptr<Course>(new Course(read));
				try {
					addCourse(toAdd);
				}
				catch (std::runtime_error & e) {
					std::cerr << e.what() << std::endl;
				}
			}
		}
		intake.close();
	}
	for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
		std::cout << (*cursor)->getHash() << std::endl;
	}
	loaded = true;
}

void CourseMap::addCourse(std::shared_ptr<Course> course) {
	auto index = course->getHash();
	if (courses.size() == 0) {
		courses.push_back(course);
	}
	else {

		for (cursor = courses.begin(); cursor != courses.end(); ++cursor) {
			if (index == (*cursor)->getHash()) {
				throw std::runtime_error(course->getInfo(0) + " already in list.");
			}
			else if (index > (*cursor)->getHash()) {
				courses.insert(cursor, course);
				break;
			}
			if (cursor == courses.end()-1) {
				courses.push_back(course);
				break;
			}


		}


	}
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

		
		cursor = courses.begin();
		while (index <= (*cursor)->getHash()) {
			if (index == (*cursor)->getHash()) {	
				return *cursor;
			}
			++cursor;
		}
		throw std::invalid_argument("Error: Course not found");
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