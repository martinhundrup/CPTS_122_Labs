
/*
	Martin Hundrup

	Defines all the test cases for testing the linked list implemented in Lab2.h and Lab2.c

	Instructions:
	Test your application. Using your current understanding of testing and
	creativity, write some test functions. In the same project, create one more
	header file testList.h and source file testList.c (for a total of at least
	five files). The testList.h file should contain function prototypes for test
	functions you will use on your list functions. The testList.c source file
	should contain the implementations for these test functions. You will be
	designing and implementing unit tests. You will have at least one test function
	per application function. Your test functions must display a message “test
	failed” or “test passed” depending on the results. For example, you will have
	an application function called deleteContact() (or a function very similar)
	that was used to remove contact information from the list. In this task, you will
	need to create a test function called testDeleteContact() that passes in
	various contact information directly into deleteNode() to see if it works
	correctly.
*/

#ifndef TESTLIST_H
#define TESTLISH_H

#define _CRT_SECURE_NO_WARNINGS

// ensures the functionality of makeNode()
void testMakeNode();

// ensures the functionality of insertContactInOrder()
void testInsertContactInOrder();

// ensures the functionality of deleteContact()
void testDeleteContact();

// ensures the functionality of editContact()
void testEditContact();

// ensures the functionality of loadContacts()
void testLoadContacts();

// ensures the functionality of storeContacts()
void testStoreContacts();

// ensures the functionality of printLists()
void testPrintList();

#endif