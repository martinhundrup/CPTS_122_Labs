#pragma once
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

using std::string;
using std::ostream;

/// <summary>
/// Represents a person's gender.
/// </summary>
enum Gender {
	Male,
	Female,
	NonBinary,
	Other
};

typedef struct course {

	string name;
	int credits;
	double grade;
} Course;

ostream& operator<<(ostream& lhs, course& rhs) {
	lhs << " | course: " << rhs.name << " | credits: " << rhs.credits << " | grade: " << rhs.grade;
	return lhs;
}

bool operator==(Course& lhs, course& rhs) {
	return (lhs.name == rhs.name);
}