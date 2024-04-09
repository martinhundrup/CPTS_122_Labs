#pragma once
#include "Lab12.hpp"

template <typename T>
class Node {

private:

	// the data stored in the node
	T key;

	// a pointer to the next successive node
	Node<T>* pNext;

	// print the key to the stream
	friend std::ostream& operator<<(std::ostream& lhs, const Node<T>& rhs) {

		lhs << rhs.key;
		return lhs;
	}

public:

	// basic constructor
	Node(T nKey = T()) {

		key = nKey;
		pNext = nullptr;
	}

	// copy constructor
	Node(Node<T>& other) {

		key = other.key;
		pNext = nullptr; // should this be null or other.pNext? why?
	}

	// gets the key // why don't I have a setter?
	T getData() const{

		return key;
	}

	// gets a pointer to the next node // what would happen if it was a Node<T>*&?
	Node<T>* getNext() const{
		
		return pNext;
	}

	// sets the next pointer to a newly allocated node
	void setNext(T nData) {

		pNext = new Node<T>(nData);
	}

	// sets the next pointer to a newly allocated node
	void setNext(Node<T>* nNext) {

		pNext = nNext;
	}
};