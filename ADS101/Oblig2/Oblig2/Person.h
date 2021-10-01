#pragma once
#include <string.h>
#include <iostream>
class Person
{
public:
	Person();
	Person(std::string newName, double n_x, double n_y) {
		name = newName;
		x = n_x;
		y = n_y;
	};
	std::string name;
	double x;
	double y;
};

