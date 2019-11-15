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

Course* CourseMap::getCourse(std::string title) {
	//find course and return pointer
	//or throw error
}

void CourseMap::deleteCourse(std::string title) {
	//binary search for course by hash
	//error if no course
}