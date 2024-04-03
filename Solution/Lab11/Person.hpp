#pragma once

#include "Lab11.hpp"

class Person {

//private:
protected:

	/// <summary>
	/// Represents this person's age.
	/// </summary>
	int age;

	/// <summary>
	/// Represents this person's full name.
	/// </summary>
	string name;

	/// <summary>
	/// Represents this person's gender.
	/// </summary>
	Gender gender;

	/// <summary>
	/// Represents this person's height in centimeters.
	/// </summary>
	double height;

public:

	/// <summary>
	/// Default constructor.
	/// </summary>
	/// <param name="nAge">The initial age.</param>
	/// <param name="nName">The initial name.</param>
	/// <param name="nGender">The initial gender.</param>
	/// <param name="nHeight">The intial height.</param>
	Person(int nAge = 0, string nName = "", Gender nGender = Other, double nHeight = 0.0) {
		age = nAge;
		name = nName;
		gender = nGender;
		height = nHeight;
	}

	/// <summary>
	/// Copy constructor.
	/// </summary>
	/// <param name="other">The person to make a copy of.</param>
	Person(const Person& other) {
		age = other.age;
		name = other.name;
		gender = other.gender;
		height = other.height;
	}

	~Person() {} // nothing dynamically allocated; no def needed

	/// <summary>
	/// Assignment operator overload.
	/// </summary>
	/// <param name="other">The person to make a copy of.</param>
	void operator=(const Person& other) {
		age = other.age;
		name = other.name;
		gender = other.gender;
		height = other.height;
	}

	friend ostream& operator<<(ostream& lhs, const Person& rhs) {
		lhs << "age: " << rhs.age << " | name: " << rhs.name << " | gender: " << rhs.genderToString() << " | height: " << rhs.age;
		return lhs;
	}

	/// <summary>
	/// Converts the person's gender to a string representation.
	/// </summary>
	/// <returns>The gender as a string.</returns>
	string genderToString() const {
		switch (gender) {
		case Male:
			return "Male";
			break;
		case Female:
			return "Female";
			break;
		case NonBinary:
			return "Non-Binary";
			break;
		default:
			return "Other";
			break;
		}
	}

	// getters
	int getAge() { return age; }
	string getName() { return name; }
	Gender getGender() { return gender; }
	double getHeight() { return height; }

	// setters
	void setAge(int x) { age = x; }
	void setName(string x) { name = x; }
	void setGender(Gender x) { gender = x; }
	void setHeight(double x) { height = x; }

};