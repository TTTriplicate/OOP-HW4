#pragma once
#include <string>
#include <array>
#include <exception>
#include <iostream>
class Course
{
	private:
		std::string data[6];
		std::size_t hashVal;
	public:
		Course();
		Course(std::string[]);
		~Course();
		std::string getInfo(int);
		std::size_t getHash();
};

