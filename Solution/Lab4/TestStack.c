#include "TestStack.h"

Bool testMakeNode() {

	// Store the exected result of makeNode
	Node* pExpected = (Node*)malloc(sizeof(Node));
	pExpected->key = 10.0;
	pExpected->pNext = NULL;

	// Store the actual result of makeNode
	Node* pActual = makeNode(10.0);

	if (pActual->key != pExpected->key) {

		return FALSE; // failed first test
	}

	if (pActual->pNext != pExpected->pNext) {

		return FALSE; // failed second test
	}

	return TRUE; // all the tests past
}

Bool testIsEmptyTrue() {

	Node* pHead = NULL; // represents the stack

	return isEmpty(pHead);
}

Bool testIsEmptyFalse() {

	Node* pHead = makeNode(10.0); // represents the stack

	return !isEmpty(pHead);
}

Bool testPushEmpty() {

	Node* pHead = NULL; // represents the stack

	Bool result = push(&pHead, 10.0); // push to stack and store result

	return result && pHead->key == 10.0; // returns true if both checks pass
}

Bool testPushFull() {

	Node* pHead = NULL; // represents the stack

	Bool result1 = push(&pHead, 10.0); // push to stack and store result
	Bool result2 = push(&pHead, 20.0); // push to stack and store result

	return result1 && result2 && pHead->key == 20.0 && pHead->pNext->key == 10.0; // returns true if all checks pass
}

Bool testPopEmpty() {

	Node* pHead = NULL; // represents the stack
	push(&pHead, 10.0);
	pop(&pHead);

	return pHead == NULL; // return the result
}

Bool testPopFull() {

	Node* pHead = NULL; // represents the stack
	push(&pHead, 10.0);
	push(&pHead, 20.0);
	pop(&pHead);

	return pHead->key == 10.0 && pHead->pNext == NULL; // return the result
}

Bool testPeekEmpty() {

	Node* pHead = NULL; // represents the stack

	return peek(pHead) == -1.0; // return the result
}

Bool testPeekFull() {

	Node* pHead = NULL; // represents the stack
	push(&pHead, 10.0);

	return peek(pHead) == 10.0; // return the result
}

void run_tests() {

	printf("result of testMakeNode(): %d\n", testMakeNode());
	printf("result of testIsEmptyTrue(): %d\n", testIsEmptyTrue());
	printf("result of testIsEmptyFalse(): %d\n", testIsEmptyFalse());
	printf("result of testPushEmpty(): %d\n", testPushEmpty());
	printf("result of testPushFull(): %d\n", testPushFull());
	printf("result of testPopEmpty(): %d\n", testPopEmpty());
	printf("result of testPopFull(): %d\n", testPopFull());
	printf("result of testPeekEmpty(): %d\n", testPeekEmpty());
	printf("result of testPeekFull(): %d\n", testPeekFull());
}