#pragma once
#include <string>
#include <array>
#include <exception>
class Course
{
	private:
		std::string data[6];
	public:
		Course();
		Course(std::string[]);
		~Course();
		std::string getInfo(int);
};

