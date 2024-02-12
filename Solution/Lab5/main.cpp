#include "Complex.h"

int main() {

	Complex c1 = Complex(1.5, 2.5);
	Complex c2 = Complex(3.5, 4.5);

	Complex c3 = c1.add(c2);

	std::cout << c3 << std::endl;

	Complex c4;
	c4.read();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //gets rid of everything else
	std::cin.sync();
	c4.print();
	std::cout << std::endl;

	Complex c5;
	std::cin >> c5;
	std::cout << c5 << std::endl;

	std::cout << c4 + c5 << std::endl;
	std::cout << c4 - c5 << std::endl;

	return 0;
}