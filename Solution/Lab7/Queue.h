#pragma once

#include "Node.h"

template <typename T>
class Queue {

private:

	/// <summary>
	/// The head pointer of the queue. The front of the line.
	/// </summary>
	Node<T>* pHead;

	/// <summary>
	/// The tail of the queue. The back of the line.
	/// </summary>
	Node<T>* pTail;

	/// <summary>
	/// Recursive helper function for printing the contents of the queue.
	/// </summary>
	/// <param name="">The current node to print.</param>
	void printQueue(Node<T>* pCur) const {

		if (pCur == nullptr) { // base case, we reached the end.
			std::cout << "nullptr";
			return;
		}
		// print this data
		std::cout << pCur->getData() << "->";

		// recurse to next node
		printQueue(pCur->getNextPtr());
	}

	/// <summary>
	/// Recursive helper function for destroying all nodes in the queue.
	/// </summary>
	/// <param name="pCur">The current node to destroy.</param>
	/// <returns>The number of nodes destroyed.</returns>
	int destroyNodes(Node<T>* pCur) {

		if (pCur == nullptr) { // base case: we reached end
			return 0;
		}

		// save reference to next node
		Node<T>* pTemp = pCur->getNextPtr();
		delete(pCur);

		// recursive call
		return 1 + destroyNodes(pTemp);
	}

public:

	/// <summary>
	/// Default constructor. Initializes fields to default values.
	/// </summary>
	Queue() {

		pHead = pTail = nullptr;
	}

	/// <summary>
	/// Destructor. Deletes all dynamically allocated nodes in the queue.
	/// </summary>
	~Queue() {

		destroy();
	}

	/// <summary>
	/// Gets the head pointer.
	/// </summary>
	/// <returns>A reference to the front of the queue.</returns>
	Node<T>* getHeadPtr() const {

		return pHead;
	}

	/// <summary>
	/// Gets the tail pointer.
	/// </summary>
	/// <returns>A reference to the end of the queue.</returns>
	Node<T>* getTailPtr() const {

		return pTail;
	}

	/// <summary>
	/// Checks if the queue is empty.
	/// </summary>
	/// <returns>True if empty, false if not.</returns>
	bool isEmpty() const {

		return (pHead == nullptr);
	}

	/// <summary>
	/// Inserts a node to the tail of the queue.
	/// </summary>
	/// <param name="key"></param>
	bool enqueue(T key) {

		Node<T>* pTemp = new Node<T>(key); // dynamically allocate a new node with the desired data

		if (pTemp == nullptr) { // check to make sure memory was allocated succesfully

			return false;
		}

		if (isEmpty()) {
			// in the case the queue is empty, the tail and head point to the same place.
			pTail = pHead = pTemp;
			return true;
		}

		pTail->setNextPtr(pTemp); // make sure the tail now points at it
		pTail = pTemp; // update tail

		return true;
	}

	/// <summary>
	/// Deletes a node from the head of the queue.
	/// </summary>
	/// <returns>The data in the deleted node.</returns>
	T dequeue() {

		if (isEmpty()) { // can't dequeue an empty queue

			return T();
		}

		Node<T>* pTemp = pHead; // store reference to current head
		T data = pTemp->getData(); // store the data in the current head

		pHead = pHead->getNextPtr(); // update the head ptr
		delete(pTemp); // delete the old head

		// if we deleted the last item in the queue, update the tail to reflect this
		if (isEmpty()) {
			pHead = nullptr;
		}

		return data;
	}

	/// <summary>
	/// Recursively prints out the data in the queue.
	/// </summary>
	void printQueue() const {

		// call recursive helper function
		printQueue(pHead);
	}

	/// <summary>
	/// Recursive function that insert the queue into a ostream object.
	/// </summary>
	/// <param name="lhs">The ostream to insert to.</param>
	/// <param name="pCur">The current node to output.</param>
	void printQueue(std::ostream& lhs, Node<T>* pCur) const {

		if (pCur == nullptr) { // base case, we reached the end.
			lhs << "nullptr";
			return;
		}

		// print this data
		lhs << pCur->getData() << "->";

		// recurse to next node
		return printQueue(lhs, pCur->getNextPtr());
	}

	/// <summary>
	/// Deletes every node in the current queue.
	/// </summary>
	/// <returns>The number of nodes destroyed.</returns>
	int destroy() {

		int val = destroyNodes(pHead);
		pHead = pTail = nullptr;
		return val;
	}
};

/// <summary>
/// Stream insertion operator overload.
/// </summary>
/// <typeparam name="T">The type being outputted.</typeparam>
/// <param name="lhs">The ostream to output to.</param>
/// <param name="rhs">The queue being outputted.</param>
/// <returns>The ostream being outputted to.</returns>
template <typename T>
std::ostream& operator<<(std::ostream& lhs, const Queue<T>& rhs) {

	rhs.printQueue(lhs, rhs.getHeadPtr());
	return lhs;
}