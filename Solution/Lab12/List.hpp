#pragma once
#include "Lab12.hpp"
#include "Node.hpp"

template <typename T>
class List {

private:

	// pointer to the start of the list
	Node<T>* pHead;

	// pointer to the end of the list
	Node<T>* pTail;

	// recursive helper function for deleting the list
	void destroy(Node<T>* pCur) {

		if (pCur != nullptr) {

			destroy(pCur->getNext());
			delete pCur;
		}
	}

	// helper function for displaying the list
	std::ostream& print(std::ostream& lhs, Node<T>* pStart) {

		Node<T>* pTemp = pStart;
		while (pTemp != nullptr) {

			lhs << *pTemp << " -> ";
			pTemp = pTemp->getNext();
		}

		lhs << "nullptr";
		return lhs;
	}

public:

	// basic constructor
	List() {
		
		pHead = pTail = nullptr;
	}

	~List() {

		destroy();
	}

	// public interface for deleting the list
	void destroy() {

		if (!isEmpty()) {

			destroy(pHead); // calls recursive helper
			pHead = nullptr; // don't forget; this allows us to reuse the list
		}
	}

	// determines if the list contains any data
	bool isEmpty() {

		return pHead == nullptr && pTail == nullptr;
	}

	// allocates and inserts a node into the front of the list
	void insertAtFront(T nData) {

		Node<T>* pNew = new Node<T>(nData);

		if (isEmpty()) {

			pHead = pTail = pNew;
		}
		else {

			pNew->setNext(pHead);
			pHead = pNew;
		}
	}

	// allocates and inserts a node into the front of the list
	void insertAtBack(T nData) {

		Node<T>* pNew = new Node<T>(nData);

		if (isEmpty()) {

			pHead = pTail = pNew;
		}
		else {

			pTail->setNext(pNew);
			pTail = pNew;
		}
	}

	// deletes the node at the front and returns it's data
	T removeAtFront() {
		
		if (!isEmpty()) {

			Node<T>* pOld = pHead;
			T data = pOld->getData();

			pHead = pOld->getNext();
			delete pOld;

			if (pHead == nullptr) {
				pTail = nullptr;
			}

			return data;
		}

		return T();
	}

	
	// deletes the node at the back and returns it's data
	// O(1) no possible in singly linked list
	// avoid using when possible
	T removeAtBack() {

		if (!isEmpty()) {

			if (pHead == pTail) { // case: only one item in list

				T data = pHead->getData();
				delete pHead;
				pHead = pTail = nullptr;
				return data;
			}

			Node<T>* pTemp = pHead;
			// iterates until pTemp == second last node
			while (pTemp->getNext() != pTail) { 

				pTemp = pTemp->getNext();
			}

			T data = pTail->getData();
			delete pTail;
			pTemp->setNext(nullptr);

			pTail = pTemp;
			return data;
		}

		return T();
	}
	

	// prints the list to the screen
	void print() {

		print(std::cout, pHead);
	}
};