#pragma once
#include "Queue.h"

class TestQueue {

public:

	/// <summary>
	/// Runs all tests and prints the results to the screen.
	/// </summary>
	void runTests();

	/// <summary>
	/// Tests the Queue class's isEmpty() function.
	/// </summary>
	bool test_isEmpty();

	/// <summary>
	/// Tests the Queue class's enqueue() function.
	/// </summary>
	bool test_enqueue();
	
	/// <summary>
	/// Tests the Queue class's dequeue() function.
	/// </summary>
	bool test_dequeue();

	/// <summary>
	/// Tests the Queue class's destroy() function.
	/// </summary>
	bool test_destroy();
};