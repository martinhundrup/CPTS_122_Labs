#include "Stack.h"

Node* makeNode(double nData) {

	Node* newNode = (Node*)malloc(sizeof(Node)); // allocate and store memory for a node
	newNode->key = nData; // store the passed in data in the node
	newNode->pNext = NULL; // sets the next pointer to the NULL pointer

	return newNode;
}

Bool isEmpty(Node* pHead) {

	if (pHead == NULL) {

		return TRUE; // if the head pointer is NULL, the stack is empty
	}

	return FALSE; // the stack is not empty if the head pointer contains a node
}

Bool push(Node** pHead, double nData) {

	Node* newNode = makeNode(nData);

	if (newNode == NULL) {

		return FALSE; // ensures data was allocated successfully
	}

	if (isEmpty(*pHead)) {

		*pHead = newNode; // if the list is empty, the new node becomes the head node
		return TRUE;
	}
	
	newNode->pNext = *pHead; // the new node points at the head pointer
	*pHead = newNode; // the head pointer becomes the new node

	return TRUE;
}

void pop(Node** pHead) {

	if (!isEmpty(*pHead)) { // only delete something if there is a head pointer
		
		Node* pTemp = (*pHead)->pNext; // temp data to store the next node
		free(*pHead); // delete the head pointer
		*pHead = pTemp; // set the new head pointer to the old next
	}
}

double peek(Node* pHead) {

	if (isEmpty(pHead)) { 

		return -1.0; // returns a predermined value if the stack is empty
	}

	return pHead->key;
}