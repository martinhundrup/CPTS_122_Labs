#include "Lab2.h"

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
void task_1() {

	
}

// Description: Allocates space for a Node on the heap and initializes 
// the Node with the information found in newData.
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated
Node* makeNode(Contact newData) {

	// dynamically allocate new data
	Node* node = (Node*) malloc(sizeof(Node));

	// set the data members
	node->pNext = NULL;
	node->data = newData;

	// return the reference
	return node;
}

// Description: Uses makeNode () to allocate space for a new Node and 
// inserts the new Node into the list in alphabetic order('a' - 'z')
// based on the name field
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
Boolean insertContactInOrder(Node** pList, Contact newData) {

	// create our new node
	Node* node = makeNode(newData);

	Node* pCur = *pList; // the current node

	// our first edge case: the list is empty
	if (*pList == NULL) {
		*pList = node;
	}

	// the second edge case: we need to insert at front
	else if (strcmp(newData.name, pCur->data.name) <= 0) {
		node->pNext = *pList;
		*pList = node;
	}

	else {

		// loop through the list until we hit the spot we need to insert
		// or until we hit the end

		Node* pNext = pCur->pNext; // the next node

		while (2 + 2 != 5) { // forever loop becase I will exit manually

			// we will never insert before pCur due to our second edge case

			// we hit the end of the list and need to insert at end
			if (pNext == NULL) {
				pCur->pNext = node;
				break;
			}
			else if (strcmp(newData.name, pNext->data.name) <= 0) { // the spot to insert is betwee pCur and pNext
				node->pNext = pNext;
				pCur->pNext = node;
				break; // exits while loop
			}

			// update vars for next loop
			pCur = pCur->pNext;
			pNext = pCur->pNext;
		}
	}

	return TRUE;
}

// Description: Deletes a Contact in the list based on the name field; 
// deletes the first occurence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean deleteContact(Node** pList, Contact searchContact) {

	Node* pCur = *pList; // the current node


	// edge case 1: list is empty
	if (*pList == NULL)
		return FALSE;

	// edge case 2: the contact is the first node
	if (strcmp(pCur->data.name, searchContact.name) == 0) {
		*pList = pCur->pNext;
		free(pCur);
		return TRUE;
	}

	// loop to find the contact
	// we don't need a pPrev because we already checked with edge case 2
	Node* pNext = pCur->pNext;
	while (pCur != NULL) {

		if (pNext == NULL) { // not present in list
			return FALSE;
		}

		if (strcmp(pNext->data.name, searchContact.name) == 0) { // we found it

			pCur->pNext = pNext->pNext;
			free(pNext);
			return TRUE;
		}

		// update vars for next loop
		pCur = pNext;
		if (pCur != NULL) // can't access the next field of a null value
			pNext = pCur->pNext;
	}

	return FALSE;
}

// Description: Edits a Contact in the list based on the name field; 
// edits the first occurence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
Boolean editContact(Node* pList, Contact searchContact) {

	Node* pCur = pList;

	// edge case 1: the list is empty
	if (pCur == NULL) {

		return FALSE;
	}

	// loop to find the contact
	Node* pNext = pCur->pNext;
	while (pCur != NULL) {
		
		if (strcmp(pCur->data.name, searchContact.name) == 0) { // we found it

			printf("contact found.\n");
			char temp[50];

			// get new name
			printf("\nenter the new name: ");
			fgets(temp, 49, stdin);
			strcpy(pCur->data.name, strtok(temp, "\n"));

			// get new phone
			printf("\nenter the new phone: ");
			fgets(temp, 12, stdin);
			strcpy(pCur->data.phone, strtok(temp, "\n"));

			// get new email
			printf("\nenter the new email: ");
			fgets(temp, 49, stdin);
			strcpy(pCur->data.email, strtok(temp, "\n"));

			// get new title
			printf("\nenter the new title: ");
			fgets(temp, 19, stdin);
			strcpy(pCur->data.title, strtok(temp, "\n"));


			return TRUE;
		}

		// update vars for next loop
		pCur = pNext;
		if (pCur != NULL) // can't access the next field of a null value
			pNext = pCur->pNext;
	}

	return FALSE;

}

// Description: Loads all Contact information from the given file, in 
// alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE* infile, Node** pList) {

	while (!feof(infile)) { // loop until end of file
		
		// stores current line into line array
		char line[133];
		fgets(line, 132, infile);

		// parse the string into the appropriate contact fields
		Contact new_data = { "", "", "", "" };
		strncpy(new_data.name, strtok(line, ","), 50); // name
		strncpy(new_data.phone, strtok(NULL, ","), 12); // phone
		strncpy(new_data.email, strtok(NULL, ","), 50); // email
		strncpy(new_data.title, strtok(NULL, ",\n"), 20); // title

		// add the contact to the list
		insertContactInOrder(pList, new_data);
	}

	return TRUE;
}

// Description: Stores all Contact information from the list into the 
// given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
Boolean storeContacts(FILE* infile, Node* pList) {

	Node* pCur = pList;
	
	// edge case 1: the list is empty
	if (pCur == NULL) {

		return TRUE;
	}

	// loop to store
	Node* pNext = pCur->pNext;
	while (pCur != NULL) {
		fprintf(infile, "%s,%s,%s,%s", pCur->data.name, pCur->data.phone,
			pCur->data.email, pCur->data.title);

		if (pNext != NULL) // print new line if we have more data on the way
			fprintf(infile, "\n");

		// update vars for next loop
		pCur = pNext;
		if (pCur != NULL) // can't access the next field of a null value
			pNext = pCur->pNext;
	}

	return TRUE;
}

// Description: Prints all contact information in the list
// Returns: Nothing
void printList(Node* pList) {

	Node* pCur = pList;


	// edge case 1: the list is empty
	if (pCur == NULL) {

		return TRUE;
	}

	// loop to print
	Node* pNext = pCur->pNext;
	while (pCur != NULL) {
		printf("%s,%s,%s,%s\n", pCur->data.name, pCur->data.phone,
			pCur->data.email, pCur->data.title);

		// update vars for next loop
		pCur = pNext;
		if (pCur != NULL) // can't access the next field of a null value
			pNext = pCur->pNext;
	}

	return TRUE;
}

// displays the program menu
void printMenu() {

	printf("welcome to PA2, please select a choice:\n");
	printf("\t1. load from file\n");
	printf("\t2. save to file\n");
	printf("\t3. display contacts\n");
	printf("\t4. add contact\n");
	printf("\t5. edit contact\n");
	printf("\t6. delete contact\n");	
	printf("\t7. exit program\n");
}