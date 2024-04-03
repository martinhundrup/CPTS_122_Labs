#include "Registration.hpp"
//#include "Teacher.hpp"

int main() {

	Person p(18, "John", Male, 170);
	Person b = p;
	Person c(b);
	c = b;
	/*std::cout << p << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;*/

	/*TestPerson t;
	t.testStreamInsertion();
	t.testGetters();
	t.testSetters();*/

	Student s(19, "Bill", Male, 170);
	s.addCourse("cs 121", 4, 93.1);
	s.addCourse("cs 122", 4, 96.7);

	Student y(s);
	s.addCourse("phil 201", 3, 98.1);
	y.addCourse("honors 390", 3, 94.5); // somehow deep copy lol
	std::cout << s << std::endl;
	std::cout << y << std::endl;

	//task_6();

	return 0;
}