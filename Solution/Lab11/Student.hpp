#pragma once
#include "Person.hpp"

class Student : public Person {

//private:
protected:

	std::list<Course> courses; // must include <list>
	int coursesTaken;
	int totalCredits;

public:

	using Person::Person; // inherits constructor

	Student(int x, string s, Gender g, double d, int c, int cred) : Person(x, s, g, d) {
		coursesTaken = c;
		totalCredits = cred;
	}

	Student(std::list<Course> nCourses = std::list<Course>(),
		int nCoursesTaken = 0, int nTotalCredits = 0) {
		courses = nCourses;
		coursesTaken = nCoursesTaken;
		totalCredits = nTotalCredits;
	}

	string coursesToString() {

		std::stringstream output; // must include <<sstream>>

		for (Course course : courses) {

			output << course;
		}

		return output.str();
	}

	friend ostream& operator<<(ostream& lhs, Student& rhs) {
		lhs << (Person)rhs << "\ncourses:" << rhs.coursesToString() << "\ncourses taken : " 
			<< rhs.coursesTaken << " | total credits: " << rhs.totalCredits;
		return lhs;
	}

	void addCourse(Course course) {
		courses.push_back(course);
		coursesTaken++;
		totalCredits += course.credits;
	}

	void addCourse(string cName, int credits, double grade) {
		Course c = { cName, credits, grade };
		addCourse(c);
	}

	std::list<Course> getCourses() {
		return courses;
	}


};