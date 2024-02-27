#include "Node.h"

/// <summary>
/// Default constructor. Initializes fields to default values.
/// </summary>
template <typename T>
Node<T>::Node() {

	key = T(); // init to default value of data type
	pNext = nullptr; // init to nullptr
}

/// <summary>
/// Overriden constructor. Initializes key to argument.
/// </summary>
/// <param name="nKey">The data to store in this node.</param>
template <typename T> 
Node<T>::Node(T nKey) {

	key = nKey; // init to passed in value.
	pNext = nullptr; // init to nullptr.
}

/// <summary>
/// Gets the data stored in the node.
/// </summary>
/// <returns>The data stored in the node.</returns>
template <typename T>
T Node<T>::getData() {

	return key;
}

/// <summary>
/// Sets the data stored in the node.
/// </summary>
/// <param name="">The new data to store.</param>
template <typename T>
void Node<T>::setData(T nKey) {

	key = nKey;
}

/// <summary>
/// Gets the next node in the sequence.
/// </summary>
/// <returns>The node pointed to by this.</returns>
template <typename T>
Node<T>* Node<T>::getNextPtr() {

	return pNext;
}

/// <summary>
/// Sets the next node in the sequence.
/// </summary>
/// <param name="">The new next pointer.</param>
template <typename T>
void Node<T>::setNextPtr(Node<T>* nNext) {

	pNext = nNext;
}

/// <summary>
/// Dynamically creates a new node and inserts after this one.
/// </summary>
/// <param name="">The new data to store.</param>
template <typename T>
void Node<T>::setNextPtr(T nKey) {

	Node<T>* pTemp = new Node<T>(nKey); // dynamically allocate new node
	pTemp->pNext = pNext; // set the new node's next to this' next
	pNext = pTemp; // set this' next to the new node
}