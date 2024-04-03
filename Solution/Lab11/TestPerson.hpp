#pragma once

#include "Person.hpp"

class TestPerson : public Person {

public:

	void testPrivateMembers() {
		int x = age; // inaccessible if private
		string y = name; // innaccessible if private
		Gender z = gender; // innaccessible if private
		double a = height; // innaccessible if private
	}

	void testConstructor() {
		//TestPerson t(12, "name", Other, 12.3); // doesn't work
	}

	void testCopyConstructor() {
		Person p(1, "name", Other, 1.2);
		// TestPerson t(p); // doesn't work
	}

	void testAssignmentOperator() {
		Person p(1, "name", Other, 1.2);
		// TestPerson t = p; // doesn't work		
	}

	void testStreamInsertion() {
		TestPerson t;
		std::cout << t << std::endl;
	}

	void testGetters() {

		std::cout << this->getAge() << std::endl;
		std::cout << this->getName() << std::endl;
		std::cout << this->getGender() << std::endl;
		std::cout << this->getHeight() << std::endl;
	}

	void testSetters() {

		this->setAge(12);
		this->setName("hello");
		this->setGender(Male);
		this->setHeight(12.3);
	}

};