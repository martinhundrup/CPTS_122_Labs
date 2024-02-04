/*
	Martin Hundrup
	Lab2
	Due: 1/25/2024
*/

#ifndef LAB2_H
#define LAB2_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // REQUIRED for malloc
#include <string.h>


typedef enum boolean
{
	FALSE, TRUE
} Boolean;

typedef struct contact
{
	char name[50];
	char phone[12]; // ex: 18005557577
	char email[50];
	char title[20];

} Contact;

typedef struct node
{
	Contact data;
	struct node* pNext;
} Node;

/*
Build an application, in C, for storing contact information (you must have one
header file and two source files). For each contact you must store a name, phone
number, email, and professional title. Your application must support insertions in
order (based on last name), deletions, modifications, and printings of contacts.
For this task you will be required to implement a dynamic singly linked list, which
grows and shrinks at runtime. Build a menu that allows the user to add, remove,
edit, print, store, and load contact information. The store feature should write
contact information found in the list to a file. The load feature should read
contact information from the same file into the list. Note: you should store the
contact information in a struct called Contact. Each Node must be a struct,
which consists of a Contact and a pointer to the next Contact in the list.
*/
void task_1();

// runs all test and outputs the results to the screen
// a 1 means it passed, a 0 means it failed
// note that the print list and edit contact tests are expected to fail
void runTests();

// Description: Allocates space for a Node on the heap and initializes 
// the Node with the information found in newData.
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated
Node* makeNode(Contact newData);

// Description: Uses makeNode () to allocate space for a new Node and 
// inserts the new Node into the list in alphabetic order('a' - 'z')
// based on the name field
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactInOrder(Node * *pList, Contact newData);

// Description: Deletes a Contact in the list based on the name field; 
// deletes the first occurence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean deleteContact(Node * *pList, Contact searchContact);

// Description: Edits a Contact in the list based on the name field; 
// edits the first occurence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean editContact(Node * pList, Contact searchContact);

// Description: Loads all Contact information from the given file, in 
// alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE * infile, Node * *pList);

// Description: Stores all Contact information from the list into the 
// given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
Boolean storeContacts(FILE * infile, Node * pList);

// Description: Prints all contact information in the list
// Returns: Nothing
void printList(Node * pList);

// displays the program menu
void printMenu();

#endif
