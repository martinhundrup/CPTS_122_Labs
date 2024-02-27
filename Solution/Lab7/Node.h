#pragma once

#include "Lab7.h"

template <typename T>
class Node {

private:

	/// <summary>
	/// The data this node stores.
	/// </summary>
	T key;

	/// <summary>
	/// The pointer to the next node.
	/// </summary>
	Node<T>* pNext;

public:

	/// <summary>
	/// Default constructor. Initializes fields to default values.
	/// </summary>
	Node();

	/// <summary>
	/// Overriden constructor. Initializes key to argument.
	/// </summary>
	/// <param name="nKey">The data to store in this node.</param>
	Node(T nKey);

	/// <summary>
	/// Gets the data stored in the node.
	/// </summary>
	/// <returns>The data stored in the node.</returns>
	T getData();

	/// <summary>
	/// Sets the data stored in the node.
	/// </summary>
	/// <param name="">The new data to store.</param>
	void setData(T);

	/// <summary>
	/// Gets the next node in the sequence.
	/// </summary>
	/// <returns>The node pointed to by this.</returns>
	Node<T>* getNextPtr();

	/// <summary>
	/// Sets the next node in the sequence.
	/// </summary>
	/// <param name="">The new next pointer.</param>
	void setNextPtr(Node<T>*);

	/// <summary>
	/// Dynamically creates a new node and inserts after this one.
	/// </summary>
    /// <param name="">The new data to store.</param>
	void setNextPtr(T)


};