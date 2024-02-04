/// Martin Hundrup
/// Cpt_122, Lab4
/// February 8, 2024
/// Defines the function prototypes for a simple stack data structure

#ifndef STACK_H
#define STACK_H

#include "Lab4.h"

#endif 

/// <summary>
/// Contains a key and a pointer to the next node.
/// </summary>
typedef struct node {

	double key;
	struct node* pNext;
} Node;

/// <summary>
/// Allocates memory for a new node and initializes it.
/// </summary>
/// <param name="nData">: the data to store into the node.</param>
/// <returns>A pointer to the newly allocated node.</returns>
Node* makeNode(double nData);

/// <summary>
/// Determines if a stack is empty or not.
/// </summary>
/// <param name="pHead">: a pointer to the head of a stack.</param>
/// <returns>TRUE if empty, FALSE if not empty.</returns>
Bool isEmpty(Node* pHead);

/// <summary>
/// Inserts a node onto the top of the stack.
/// </summary>
/// <param name="pHead">: a double pointer to the head of the stack.</param>
/// <param name="nData">: the data to store into the node.</param>
/// <returns>TRUE if data was successfully allocated, FALSE otherwise.</returns>
Bool push(Node** pHead, double nData);

/// <summary>
/// Deletes the top node of the stack.
/// </summary>
/// <param name="pHead">: a double pointer to the head of the stack.</param>
void pop(Node** pHead);

/// <summary>
/// Returns the data in the head node of the stack.
/// </summary>
/// <param name="pHead">: a pointer to the head of the stack.</param>
/// <returns>The data stored in the top node.</returns>
double peek(Node* pHead);