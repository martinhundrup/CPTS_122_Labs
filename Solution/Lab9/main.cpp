#include "Lab9.hpp"
#include "TestStack.hpp"
#include "PostfixEvaluator.hpp"
#include "PostfixConverter.hpp"

int main() {

	/*
	* Task 0:
	* a)
	*	delete last node of linked list:	O(n)
	*	delete last node in array:			O(1)
	* b)
	*	delete first node of linked list:	O(1)
	*	delete first node in array:			O(1)
	*	delete first node in array list:	O(n)
	* c)
	*	in order of efficiency:
	*	array
	*	linked list
	*	array list
	* d)
	*	insert at end of linked list:		O(n)
	*	insert at end of array:				O(1)
	* e)
	*	insert at front of linked list:		O(1)
	*	insert at front of array:			O(1)
	*	insert at front of array list:		O(n)
	* f)
	*	in order of efficiency:
	*	array
	*	linked list
	*	array list
	* g)
	*	access in linked list:				O(n)
	*	acces in array:						O(1)
	*/



	//int item1 = -89, item2 = 104;

	////	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	//TestStack<int> tester;

	//tester.Test(item1, item2);

	/*Stack<int> stack;
	int i1 = 1, i2 = 2, i3 = 3;
	stack.push(i1);
	stack.push(i2);
	stack.push(i3);

	int temp = 0;
	for (int i = 0; i < 3; i++) {
		
		stack.pop(temp);
		std::cout << temp << std::endl;
	}*/

	//PostfixEvaluator postfixEvaluator("2 3 ^ 5 * =");
	//std::cout << postfixEvaluator.evaluate("1 2 + 4 * =") << std::endl;

	//PostfixConverter postfixConverter("1 + 2 * 5 - 7 / 8");
	//std::cout << postfixConverter.convert("1 / 2") << std::endl;


	std::cout << "enter an infix expression: ";
	std::string input = "";
	getline(std::cin, input);
	PostfixConverter c = PostfixConverter(input);
	PostfixEvaluator e = PostfixEvaluator(c.getPostfix());
	std::cout << e.getValue() << std::endl;

	return 0;
}