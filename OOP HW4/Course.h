#pragma once
#include <string>
#include <array>
#include <exception>
#include <iostream>

class Course
{
	private:
		std::string data[6];
		unsigned hashVal;
	public:
		Course();
		Course(std::string[]);
		~Course();
		std::string getInfo(int);
		//unsigned getHash();
		unsigned getHash();
		static bool compare(std::shared_ptr<Course>, std::shared_ptr<Course>);
};

