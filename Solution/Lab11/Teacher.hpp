//#pragma once
//#include "Person.hpp"
//
//class Teacher : public Person {
//
//
//private:
//
//	std::list<Course> courses; // must include <list>
//	int coursesTaken;
//	int totalCredits;
//
//public:
//
//	using Person::Person;
//
//	Teacher(std::list<Course> nCourses = std::list<Course>(),
//		int nCoursesTaken = 0, int nTotalCredits = 0) {
//		courses = nCourses;
//		coursesTaken = nCoursesTaken;
//		totalCredits = nTotalCredits;
//	}
//
//	string coursesToString() {
//
//		std::stringstream output; // must include <<sstream>>
//
//		for (Course course : courses) {
//
//			output << course;
//		}
//
//		return output.str();
//	}
//
//	friend ostream& operator<<(ostream& lhs, Teacher& rhs) {
//		lhs << (Person)rhs << "\ncourses:" << rhs.coursesToString() << "\ncourses taken : "
//			<< rhs.coursesTaken << " | total credits: " << rhs.totalCredits;
//		return lhs;
//	}
//
//};


#pragma once
#include "Student.hpp"

class Teacher : public Student {


private:

public:

	// inherits ALL constructors from student
	using Student::Student;

	// Calculates total credits taught.
	int totalCreditsTaught() {

		int sum = 0;
		for (Course course : courses) {
			sum += course.credits;
		}

		return sum;
	}

	// Calculates the average grade umong all students enrolled in all their courses.
	double averageGrades() {

		double grades = 0.0;
		int count = 0;
		for (Course course : courses) {

			count++;
			grades += course.grade;
		}

		return count == 0 ? 0.0 : (grades / count);
	}

	// Gets the number of courses taught by the teacher.
	int getNumberOfCourse() {

		int count = 0;
		for (Course course : courses) {

			count++;
		}

		return count;
	}

};