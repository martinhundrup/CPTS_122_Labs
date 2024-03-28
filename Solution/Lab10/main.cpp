#include "Mergesort.hpp"
#include "Lab10.hpp"
#include "BST.hpp"

int main() {

	Mergesort<int> intSort;
	Mergesort<std::string> strSort;

	int intArray[] = {12, 11, 13, 5, 6, 7};
	int intArraySize = sizeof(intArray) / sizeof(int);
	std::string strArray[] = {
	"orange", "banana", "apple", "grape", "pear",
	"kiwi", "strawberry", "blueberry", "raspberry", "pineapple",
	"watermelon", "melon", "cherry", "mango", "papaya",
	"apricot", "peach", "plum", "lemon", "lime",
	"coconut", "fig", "grapefruit", "nectarine", "persimmon",
	"tangerine", "passionfruit", "dragonfruit", "guava", "lychee"
	};

	int strArraySize = sizeof(strArray) / sizeof(std::string);

	std::cout << "int array is: ";
	intSort.printArray(intArray, intArraySize);

	std::cout << "str array is: ";
	strSort.printArray(strArray, strArraySize);

	intSort.sort(intArray, intArraySize);
	strSort.sort(strArray, strArraySize);

	std::cout << "sorted int array is: ";
	intSort.printArray(intArray, intArraySize);

	std::cout << "sorted str array is: ";
	strSort.printArray(strArray, strArraySize);

	BST<int> t;
	t.insert(100);
	t.insert(50);
	t.insert(150);
	t.insert(25);
	t.insert(75);
	t.insert(125);
	t.insert(175);
	t.insert(12);
	t.insert(37);
	t.insert(62);
	t.insert(87);
	t.insert(112);
	t.insert(137);
	t.insert(162);
	t.insert(187);

	t.printInOrder();
	std::cout << std::endl;

	t.deleteNode(50);

	t.printInOrder();

	return 0;
}