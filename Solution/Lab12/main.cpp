#include "Lab12.hpp"
#include "List.hpp"
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

int main(){

	/*Stack<int> list;

	for (int i = 0; i < 10; i++) {
		list.push(i);
	}

	for (int i = 0; i < 10; i++) {
		std::cout << list.pop() << std::endl;
		list.print();
		std::cout << std::endl;
	}*/

	List<int> list;

	for (int i = 0; i < 100000; i++) {

		list.insertAtFront(i * 10);
		//list.insertAtBack(i * 5);
	}

	auto start = std::chrono::high_resolution_clock::now(); // #include <chrono>

	for (int i = 0; i < 100000; i++) {

		list.removeAtBack();
		//list.removeAtFront();
		//list.print();
		//std::cout << std::endl;
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;

	std::cout << "time taken: " << duration.count() << std::endl;
	

	return 0;
}