#include "TestQueue.h"

/// <summary>
/// Runs all tests and prints the results to the screen.
/// </summary>
void TestQueue::runTests() {

	std::cout << "result of test_isEmpty(): " << test_isEmpty() << std::endl;
	std::cout << "result of test_enqueue(): " << test_enqueue() << std::endl;
	std::cout << "result of test_dequeue(): " << test_dequeue() << std::endl;
}

/// <summary>
/// Tests the Queue class's isEmpty() function.
/// </summary>
bool TestQueue::test_isEmpty() {

	Queue<std::string> stringQueue;
	Queue<int> intQueue;
	Queue<bool> boolQueue;

	stringQueue.enqueue("hello, world");

	boolQueue.enqueue(true);
	boolQueue.enqueue(false);

	return intQueue.isEmpty() && !stringQueue.isEmpty() && !stringQueue.isEmpty();
}

/// <summary>
/// Tests the Queue class's enqueue() function.
/// </summary>
bool TestQueue::test_enqueue() {

	Queue<std::string> stringQueue;
	stringQueue.enqueue("hello");
	stringQueue.enqueue("world");

	Queue<int> intQueue;
	
	Queue<bool> boolQueue;
	boolQueue.enqueue(true);

	return stringQueue.enqueue("!") && intQueue.enqueue(1) && boolQueue.enqueue(false);
}

/// <summary>
/// Tboolests the Queue class's dequeue() function.
/// </summary>
bool TestQueue::test_dequeue() {

	Queue<std::string> stringQueue;
	stringQueue.enqueue("hello");
	stringQueue.enqueue("world");

	Queue<int> intQueue;
	intQueue.enqueue(1);

	Queue<bool> boolQueue;

	bool val1 = stringQueue.dequeue() == "hello";
	bool val2 = intQueue.dequeue() == 1;
	bool val3 = boolQueue.dequeue() == false;

	return val1 && val2 && val3;
}