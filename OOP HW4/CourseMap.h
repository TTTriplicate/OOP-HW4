#pragma once
#include "Course.h"
#include <vector>
#include <string>
#include <memory>

class CourseMap
{
	private:
		std::vector<Course> courses;
		std::vector<Course>::iterator cursor;
		void addCourse(Course);
		bool loaded = false;
	public:
		CourseMap();
		~CourseMap();
		void loadCourses(std::string);
		void deleteCourse(std::string);
		std::shared_ptr<Course> getCourse(std::string);
};

