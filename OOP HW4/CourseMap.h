#pragma once
#include "Course.h"
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

class CourseMap
{
	private:
		std::vector<std::shared_ptr<Course>> courses;//sorted descending
		std::vector<std::shared_ptr<Course>>::iterator cursor;
		void addCourse(std::shared_ptr<Course>);
		bool loaded = false;
	public:
		CourseMap();
		~CourseMap();
		void loadCourses(std::string);
		void deleteCourse(std::string);
		std::shared_ptr<Course> getCourse(std::string);
};

