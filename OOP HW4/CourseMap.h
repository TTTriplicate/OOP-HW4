#pragma once
#include "Course.h"
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
		bool loaded = false;
	public:
		CourseMap();
		~CourseMap();
		void loadCourses(std::string);
		void addCourse(std::shared_ptr<Course>);
		void deleteCourse(std::string);
		void setLoadstate();
		bool isLoaded();
		std::shared_ptr<Course> getCourse(std::string);
		void sortCourses();
};

