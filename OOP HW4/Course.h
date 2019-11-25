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
		bool good = true;//not a zombie, flips if constructor fails
	public:
		Course();
		Course(std::string[]);
		~Course();
		void isGood();//zombie check
		std::string getInfo(int);
		std::size_t getHash();
		static bool compare(std::shared_ptr<Course>, std::shared_ptr<Course>);//allows use of std::sort
};

