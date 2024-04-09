#pragma once
#include "Lab12.hpp"
#include "List.hpp"

template <typename T>
class Stack : private List<T> {

public:

	// basic constructor
	Stack() : List<T>() {

	}

	// adds an item to the back of the queue
	void push(T data) {

		this->insertAtFront(data);
	}

	// removes an item from the front of the queue
	T pop() {

		return this->removeAtFront();
	}

	// prints the stack to the screen
	void print() {

		List<T>::print(); // ensures we call the list's print and not our own recusively
	}
};