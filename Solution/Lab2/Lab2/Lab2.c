#include "Lab2.h"
#include "TestList.h"


// runs all test and outputs the results to the screen
// a 1 means it passed, a 0 means it failed
// note that the print list and edit contact tests are expected to fail
void runTests() {

	printf("make node test: %d\n", testMakeNode());
	printf("insert contact in order: %d\n", testInsertContactInOrder());
	printf("delete contact: %d\n", testDeleteContact());
	printf("edit contact: %d\n", testEditContact());
	printf("load contact: %d\n", testLoadContacts());
	printf("store contact: %d\n", testStoreContacts());
	printf("print list: %d\n", testPrintList());
}

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

	Node* pList = NULL; // our contact list instantiation

	int choice = 0;
	Boolean contacts_loaded = FALSE;

	while (choice != 7) {

		// start of program, clear screen then display menu
		system("cls");
		printMenu();

		// get user input
		scanf("%d", &choice);
		getchar();

		if (choice < 1 || choice > 7) {
			printf("please enter a valid value\n");
			system("pause");
		}
		else if (choice == 1) { // load from file
			// read from file
			FILE* infile = fopen("infile.txt", "r");
			if (loadContacts(infile, &pList)) { // successful load
				fclose(infile);
				printf("contacts loaded successfully.\n");
				contacts_loaded = TRUE;
				system("pause");
			}
			else { // unsuccessful load
				fclose(infile);
				printf("contacts failed to load.\n");
				system("pause");
			}
		}
		else if (choice == 2) { // save to file
			// make sure we have loaded so far
			if (contacts_loaded == FALSE) {
				printf("you must load contacts first.\n");
				system("pause");
			}
			else {

				FILE* outfile = fopen("infile.txt", "w");
				// write to file
				if (storeContacts(outfile, pList)) {
					fclose(outfile);
					printf("contacts saved successfully.\n");
					system("pause");
				}
				else {
					fclose(outfile);
					printf("contacts failed to save.\n");
					system("pause");
				}
			}
		}
		else if (choice == 3) { // display contact list to screen
			printList(pList);
			system("pause");
		}
		else if (choice == 4) { // creates a new contact
			Contact temp;

			// get new name
			printf("\nenter the name: ");
			fgets(temp.name, 49, stdin);
			strcpy(temp.name, strtok(temp.name, "\n"));

			// get new phone
			printf("\nenter the phone: ");
			fgets(temp.phone, 12, stdin);
			strcpy(temp.phone, strtok(temp.phone, "\n"));

			// get new email
			printf("\nenter the email: ");
			fgets(temp.email, 49, stdin);
			strcpy(temp.email, strtok(temp.email, "\n"));

			// get new title
			printf("\nenter the title: ");
			fgets(temp.title, 19, stdin);
			strcpy(temp.title, strtok(temp.title, "\n"));

			if (insertContactInOrder(&pList, temp) == TRUE) {
				printf("\ncontact entered successfully\n");
				system("pause");
			}
			else {
				printf("\ncontact failed to be created\n");
				system("pause");
			}
		}
		else if (choice == 5) { // edit contact

			printf("\nplease enter the contact name: ");
			char temp[50];
			fgets(temp, 49, stdin);
			Contact c;
			strcpy(c.name, strtok(temp, "\n"));
			if (editContact(pList, c) == FALSE) {
				printf("contact not found.\n");
				system("pause");
			}
			else {
				printf("contact changed successfully.\n");
				system("pause");
			}
		}
		else if (choice == 6) { // delete contact

			printf("\nplease enter the contact name: ");
			char temp[50];
			fgets(temp, 49, stdin);
			Contact c;
			strcpy(c.name, strtok(temp, "\n"));
			if (deleteContact(&pList, c) == FALSE) {
				printf("contact not found.\n");
				system("pause");
			}
			else {
				printf("contact deleted successfully.\n");
				system("pause");
			}
		}
	}
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

	Node* node = makeNode(newData); // create our new node

	// our first edge case: the list is empty
	if (*pList == NULL) {

		*pList = node;
		return TRUE;
	}

	// the second edge case: we need to insert at front
	if (strcmp(newData.name, (*pList)->data.name) <= 0) {

		node->pNext = *pList;
		*pList = node;

		return TRUE;
	}

	Node* pCur = *pList; // the current node
	Node* pNext = pCur->pNext; // the next node

	// loop through the list until we hit the spot we need to insert
	// or until we hit the end
	while (pCur != NULL) { // make sure we don't try to access a null pointer

		// we will never insert before pCur due to our second edge case

		// we hit the end of the list and need to insert at end
		if (pNext == NULL) {
			pCur->pNext = node;

			return TRUE; // exits the while loop
		}
		else if (strcmp(newData.name, pNext->data.name) <= 0) { // the spot to insert is between pCur and pNext

			node->pNext = pNext;
			pCur->pNext = node;

			return TRUE; // exits while loop
		}

		// update vars for next loop
		pCur = pCur->pNext;
		pNext = pCur->pNext;
	}

	return FALSE; // we never found a node to delete
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

	Node* pNext = pCur->pNext; // a pointer to the next node, will be the one we free()

	// loop to find the contact
	// we don't need a pPrev because we already checked with edge case 2
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

	// edge case 1: the list is empty
	if (pList == NULL) {

		return FALSE;
	}

	// loop to find the contact
	Node* pCur = pList; // pointer to current node
	Node* pNext = pCur->pNext; // pointer to next node	
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

	return FALSE; // if we reach here, then there was no contact found
}

// Description: Loads all Contact information from the given file, in 
// alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
Boolean loadContacts(FILE* infile, Node** pList) {

	if (infile == NULL) { // if the file isn't open, return false
		return FALSE; 
	}

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

	
	// edge case 1: the list is empty
	if (pList == NULL) {

		return FALSE;
	}

	// loop to store
	Node* pCur = pList; // pointer to current node
	Node* pNext = pCur->pNext; // pointer to next node
	while (pCur != NULL) {

		// print the node data
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

	// edge case 1: the list is empty
	if (pList == NULL) {

		return;
	}

	// loop to print
	Node* pCur = pList; // pointer to current node
	Node* pNext = pCur->pNext; // pointer to next node
	while (pCur != NULL) {
		// print the node data
		printf("%s,%s,%s,%s\n", pCur->data.name, pCur->data.phone,
			pCur->data.email, pCur->data.title);

		// update vars for next loop
		pCur = pNext;
		if (pCur != NULL) // can't access the next field of a null value
			pNext = pCur->pNext;
	}
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