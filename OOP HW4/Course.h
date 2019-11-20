#pragma once
#include <string>
#include <array>
#include <exception>
#include <iostream>
#include <algorithm>

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
		//std::size_t getHash();
		const std::size_t getHash() const;
		static bool compare(std::shared_ptr<Course>, std::shared_ptr<Course>);
};

