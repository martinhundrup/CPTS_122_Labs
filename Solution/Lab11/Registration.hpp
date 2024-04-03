#pragma once

#include "Teacher.hpp"

// Runs task 6.
void task_6();

// Determines if a student is enrolled in a course.
bool is_enrolled(Student, Course);

// Registers a student for a course.
void register_for_class(Student, Course);

// Calculates the average grade among all students enrolled in a course
double calculate_average_grade(std::list<Student>, Course);


// Runs task 6.
void task_6() {

	Course cs_121 = { "Cpt_S 121", 4, 0.0 };
	Course cs_122 = { "Cpt_S 122", 4, 0.0 };
	Course cs_223 = { "Cpt_S 223", 3, 0.0 };
	Course cs_260 = { "Cpt_S 260", 3, 0.0 };
	Course cs_321 = { "Cpt_S 321", 3, 0.0 };
	Course cs_317 = { "Cpt_S 317", 3, 0.0 };
	
	Teacher andy = Teacher(35, "Andy O'Fallon", Male, 175);
	Teacher vanera = Teacher(35, "Vanera Arnaoudova", Female, 155);
	Teacher assefaw = Teacher(35, "Assefaw Gebremedhin", Male, 185);
	Teacher yan = Teacher(35, "Yan Yan", Male, 165);

	andy.addCourse(cs_121);
	andy.addCourse(cs_122);
	yan.addCourse(cs_223);
	yan.addCourse(cs_260);
	assefaw.addCourse(cs_317);
	vanera.addCourse(cs_321);

	Student bill = Student(19, "Bill", Male, 180);
	Student jean = Student(20, "Jean", Female, 150);
	Student john = Student(20, "John", NonBinary, 185);

	Student students[] = {bill, jean, john};
	Teacher teachers[] = {andy, vanera, assefaw, yan};
	Course courses[] = { cs_121, cs_122, cs_223, cs_260, cs_321, cs_317 };

	while (true) {

		system("cls");
		std::cout << "Courses: " << '\n' << cs_121 << "\n" << cs_122 << '\n' << cs_223 << '\n' << cs_260 << '\n' << cs_321 << '\n' << cs_317 << '\n';

		std::cout << "Teachers: " << '\n' << andy << '\n' << vanera << '\n' << assefaw << '\n' << yan << '\n';

		std::cout << "Students: " << "\n1: " << bill << "\n2: " << jean << "\n3: " << john << '\n';

		std::cout << "pick a student to enroll in a course: ";

		int student_index = 0;
		std::cin >> student_index;

		if (student_index <= 3 && student_index >= 1) { // valid input

			system("cls");
			
			std::cout << "Teachers: " << "\n1: " << andy << "\n2: " << vanera << "\n3: " << assefaw << "\n4: " << yan << '\n';

			std::cout << "Student to enroll: " << students[student_index - 1] << std::endl;

			int teacher_index;
			std::cout << "pick a teacher: ";
			std::cin >> teacher_index;
			if (teacher_index <= 4 && teacher_index >= 1) { // valid input

				system("cls");

				std::cout << "Courses taught: " << std::endl;
				int i = 1;
				for (Course course : teachers[teacher_index - 1].getCourses()) {
					std::cout << i++ << ": " << course << std::endl;
				}

				std::cout << "select course to enroll in: ";
				int course_index = 0;
				std::cin >> course_index;

				if (course_index <= teachers[teacher_index - 1].getNumberOfCourse() && course_index >= 1) {

					system("cls");
					std::cout << "what is the students grade in this course: ";
					double grade = 0.0;
					std::cin >> grade;
					Course temp = courses[course_index - 1];
					temp.grade = grade;
					students[student_index - 1].addCourse(temp);

		
				}
			}
		}
	}


}

// Determines if a student is enrolled in a course.
bool is_enrolled(Student student, Course course) {

	for (Course n : student.getCourses()) {
		if (n == course) {
			return true;
		}
	}

	return false;
}

// Registers a student for a course.
void register_for_class(Student student, Course course) {

	if (!is_enrolled(student, course)) {
		student.addCourse(course);
	}
}

// Calculates the average grade among all students enrolled in a course
double calculate_average_grade(std::list<Student> students, Course course) {

	double grade = 0.0;
	int count = 0;
	for (Student student : students) {
		for (Course c : student.getCourses()) {
			if (c == course) {
				count++;
				grade += c.grade;
			}
		}
	}

	return count == 0 ? 0.0 : (grade / count);
}

