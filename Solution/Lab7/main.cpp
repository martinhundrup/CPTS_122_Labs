#include "TestQueue.h"

int main(void) {

	/// queue of queues

	/*Queue<std::string> stringQueue1;
	stringQueue1.enqueue("hello");
	stringQueue1.enqueue("world");

	Queue<std::string> stringQueue2;
	stringQueue2.enqueue("my");
	stringQueue2.enqueue("name");

	Queue<std::string> stringQueue3;
	stringQueue3.enqueue("is");
	stringQueue3.enqueue("bob!");

	Queue<Queue<std::string>> queue;
	queue.enqueue(stringQueue1);
	queue.enqueue(stringQueue2);
	queue.enqueue(stringQueue3);

	std::cout << queue << std::endl;*/

	/// queue of queue of queues

	/*Queue<int> queue1;
	queue1.enqueue(1);
	queue1.enqueue(2);

	Queue<int> queue2;
	queue2.enqueue(3);
	queue2.enqueue(4);

	Queue<int> queue3;
	queue1.enqueue(5);
	queue1.enqueue(6);

	Queue<int> queue4;
	queue2.enqueue(7);
	queue2.enqueue(8);

	Queue<Queue<int>> queue10;
	queue10.enqueue(queue1);
	queue10.enqueue(queue2);

	Queue<Queue<int>> queue20;
	queue20.enqueue(queue3);
	queue20.enqueue(queue4);

	Queue<Queue<Queue<int>>> queue100;
	queue100.enqueue(queue10);
	queue100.enqueue(queue20);

	std::cout << queue100 << std::endl;*/

	// bonus pts: what's the expected output?


	TestQueue testQueue;
	testQueue.runTests();

	return 0;
}