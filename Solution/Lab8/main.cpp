#include "BST.hpp"
#include "AVLTree.hpp"

void task_3() {

	BST<std::string> bst;

	std::string names[100];
	
	std::ifstream infile("names.txt");

	// store into array
	for (int i = 0; !infile.eof(); i++) {
		infile >> names[i];
	}

	// foreach loop in cpp
	// store into bst
	for (std::string s : names) {
		bst.insert(s);
	}

	std::string* array = bst.fillArray();

	for (int i = 0; i < bst.countNodes(); i++) {
		std::cout << array[i] << std::endl;
	}
}

int main() {

	task_3();

	

	return 0;
}