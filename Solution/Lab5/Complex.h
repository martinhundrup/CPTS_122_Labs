#pragma once

#include "Lab5.h"

class Complex {

private:

	// represents the real part of the imaginary number
	double realPart;

	// represents the complex part of the imaginary number
	double imaginaryPart;

public:

	/// <summary>
	/// Default constructor. Initializes all values to 0.
	/// </summary>
	Complex();

	/// <summary>
	/// Overloaded constructor. Initializes values to those passed in.
	/// </summary>
	/// <param name="">The initial realPart value.</param>
	/// <param name="">The initial imaginaryPart value.</param>
	Complex(double, double);

	/// <summary>
	/// Adds the data members of argument to this object.
	/// </summary>
	/// <param name="rhs">The Complex value to add.</param>
	/// <returns>A new Complex value containing the new values.</returns>
	Complex add(Complex& rhs);
	
	/// <summary>
	/// Subtracts the data members of argument from this object.
	/// </summary>
	/// <param name="rhs">The Complex value to subtract.</param>
	/// <returns>A new Complex value containing the new values.</returns>
	Complex sub(Complex& rhs);

	/// <summary>
	/// Reads values from cin in the form a + bi and updates data members.
	/// </summary>
	void read();

	/// <summary>
	/// Prints data members to cout in the form a + bi;
	/// </summary>
	void print();

	/// <summary>
	/// Getter for the realPart private data member.
	/// </summary>
	/// <returns>The value of realPart.</returns>
	double getRealPart() const;

	/// <summary>
	/// Setter for the realPart private data member.
	/// </summary>
	/// <param name="newValue">The new value to override with.</param>
	void setRealPart(double newValue);

	/// <summary>
	/// Getter for the imaginaryPart private data member.
	/// </summary>
	/// <returns>The value of imaginaryPart.</returns>
	double getImaginaryPart() const;

	/// <summary>
	/// Setter for the imaginaryPart private data member.
	/// </summary>
	/// <param name="newValue">The new value to override with.</param>
	void setImaginaryPart(double newValue);

	/// <summary>
	/// Stream extraction operator overload for the Complex class.
	/// </summary>
	/// <param name="lhs">The left side of the operation.</param>
	/// <param name="rhs">The right side of the operation.</param>
	/// <returns>The stream to take the data from.</returns>
	friend std::istream& operator>> (std::istream& lhs, Complex& rhs);
};

/// <summary>
/// Non-member addition function for the Complex class.
/// </summary>
/// <param name="lhs">The left side of the + operation.</param>
/// <param name="rhs">The right side of the + operation.</param>
/// <returns>A new complex number with the resulting values.</returns>
Complex add(Complex& lhs, Complex& rhs);

/// <summary>
/// Non-member subtraction function for the Complex class.
/// </summary>
/// <param name="lhs">The left side of the - operation.</param>
/// <param name="rhs">The right side of the - operation.</param>
/// <returns>A new complex number with the resulting values.</returns>
Complex sub(Complex& lhs, Complex& rhs);

/// <summary>
/// '+' opperator overload for the Complex class.
/// </summary>
/// <param name="lhs">The left side of the operation.</param>
/// <param name="rhs">The right side of the operation.</param>
/// <returns>A new complex number containing the results of the operation.</returns>
Complex operator+ (const Complex& lhs, const Complex& rhs);

/// <summary>
/// '-' opperator overload for the Complex class.
/// </summary>
/// <param name="lhs">The left side of the operation.</param>
/// <param name="rhs">The right side of the operation.</param>
/// <returns>A new complex number containing the results of the operation.</returns>
Complex operator- (const Complex& lhs, const Complex& rhs);

/// <summary>
/// Stream insertion operator overload for the Complex class.
/// </summary>
/// <param name="lhs">The left side of the operation.</param>
/// <param name="rhs">The right side of the operation.</param>
/// <returns>The stream output the data to.</returns>
std::ostream& operator<< (std::ostream& lhs, const Complex& rhs);