#pragma once
#include "Course.h"
#include <vector>
#include <string>

class CourseMap
{
	private:
		std::vector<Course> courses;
		void addCourse(Course);
		bool loaded = false;
	public:
		CourseMap();
		~CourseMap();
		void loadCourses(std::string);
		void deleteCourse(std::string);
		Course* getCourse(std::string);
};

