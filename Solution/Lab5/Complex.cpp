#include "Complex.h"

Complex::Complex() {

	this->realPart = 0.0;
	this->imaginaryPart = 0.0;
}

Complex::Complex(double x, double y) {

	this->realPart = x;
	this->imaginaryPart = y;
}

Complex Complex::add(Complex& rhs) {

	this->realPart += rhs.realPart;
	this->imaginaryPart += rhs.imaginaryPart;

	return Complex(this->realPart, this->imaginaryPart);
}

Complex Complex::sub(Complex& rhs) {

	this->realPart -= rhs.realPart;
	this->imaginaryPart -= rhs.imaginaryPart;

	return Complex(this->realPart, this->imaginaryPart);
}

void Complex::read() {

	int temp = 0;
	std::string garbage;

	// read real part
	std::cin >> temp;
	this->realPart = temp;

	// throw away +/-
	std::cin >> garbage;

	// get imaginary part
	std::cin >> temp;
	this->imaginaryPart = temp;
}

void Complex::print() {

	std::cout << this->realPart << " + " << this->imaginaryPart << "i";
}

double Complex::getRealPart() const {

	return this->realPart;
}

void Complex::setRealPart(double newValue) {

	this->realPart = newValue;
}

double Complex::getImaginaryPart() const {

	return this->imaginaryPart;
}

void Complex::setImaginaryPart(double newValue) {

	this->imaginaryPart = newValue;
}

Complex add(Complex& lhs, Complex& rhs) {

	return Complex(lhs.getRealPart() + rhs.getRealPart(), lhs.getImaginaryPart() + rhs.getImaginaryPart());
}

Complex sub(Complex& lhs, Complex& rhs) {

	return Complex(lhs.getRealPart() - rhs.getRealPart(), lhs.getImaginaryPart() - rhs.getImaginaryPart());
}

Complex operator+ (const Complex& lhs, const Complex& rhs) {

	return Complex(lhs.getRealPart() + rhs.getRealPart(), lhs.getImaginaryPart() + rhs.getImaginaryPart());
}

Complex operator- (const Complex& lhs, const Complex& rhs) {

	return Complex(lhs.getRealPart() - rhs.getRealPart(), lhs.getImaginaryPart() - rhs.getImaginaryPart());
}

std::istream& operator>> (std::istream& lhs, Complex& rhs) {

	std::string garbage;
	lhs >> rhs.realPart >> garbage >> rhs.imaginaryPart;

	return lhs;
}

std::ostream& operator<< (std::ostream& lhs, const Complex& rhs) {

	lhs << rhs.getRealPart() << " + " << rhs.getImaginaryPart() << "i";
	return lhs;
}