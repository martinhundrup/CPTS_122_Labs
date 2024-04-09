#pragma once
#include "Lab12.hpp"
#include "List.hpp"

template <typename T>
class Queue : private List<T> {

public:

	// basic constructor
	Queue() : List<T>() {

	}

	// adds an item to the back of the queue
	void enqueue(T data) {

		this->insertAtBack(data);
	}

	// removes an item from the front of the queue
	T dequeue() {

		return this->removeAtFront();
	}

	// prints the queue to the screen
	void print() {

		List<T>::print(); // ensures we call the list's print and not our own recusively
	}
};