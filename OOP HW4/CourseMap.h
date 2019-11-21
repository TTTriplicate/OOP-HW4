#pragma once
#include "Course.h"
#include <vector>
#include <fstream>

class CourseMap
{
	private:
		std::vector<std::shared_ptr<Course>> courses;//sorted ascending
		std::vector<std::shared_ptr<Course>>::iterator cursor;//having this here allows for the delete functionality I made
		bool loaded = false;
	public:
		CourseMap();
		~CourseMap();
		void addCourse(std::shared_ptr<Course>);
		void deleteCourse(std::string);
		void setLoadstate();
		bool isLoaded();
		std::shared_ptr<Course> getCourse(std::string);
		void sortCourses();
};

