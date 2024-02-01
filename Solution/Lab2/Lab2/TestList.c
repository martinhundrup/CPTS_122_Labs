#include "TestList.h"

// ensures the functionality of makeNode()
Boolean testMakeNode() {

	// create contact to test against
	Contact testContact = { "test", "01234567890", "test@gmail.com", "testing function"};
	
	Node* pNode = makeNode(testContact); // a node* that stores the result of makeNode()

	if (strcmp(pNode->data.name, testContact.name) == 0 && strcmp(pNode->data.phone, testContact.phone) == 0 &&
		strcmp(pNode->data.email, testContact.email) == 0 && strcmp(pNode->data.title, testContact.title) == 0) {

		return TRUE; // all values are equal
	}

	return FALSE;
}

// ensures the functionality of insertContactInOrder()
Boolean testInsertContactInOrder() {

	// create a contact for the back of the list
	Contact front = { "test a", "a01234567890", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "c01234567890", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "b01234567890", "testb@gmail.com", "btesting function" };

	Node* pList = NULL; // the testing linked list

	if (!insertContactInOrder(&pList, middle)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, front)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, back)) {
		return FALSE; // the insertion failed
	}

	// test the values of front
	if (strcmp(pList->data.name, front.name) != 0 || strcmp(pList->data.phone, front.phone) != 0 ||
		strcmp(pList->data.email, front.email) != 0 || strcmp(pList->data.title, front.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}
	
	Node* pNext = pList->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of middle
	if (strcmp(pNext->data.name, middle.name) != 0 || strcmp(pNext->data.phone, middle.phone) != 0 ||
		strcmp(pNext->data.email, middle.email) != 0 || strcmp(pNext->data.title, middle.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	pNext = pNext->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of back
	if (strcmp(pNext->data.name, back.name) != 0 || strcmp(pNext->data.phone, back.phone) != 0 ||
		strcmp(pNext->data.email, back.email) != 0 || strcmp(pNext->data.title, back.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	return TRUE; // if we get here, we passed all the tests and can pass the overall test
}

// ensures the functionality of deleteContact()
Boolean testDeleteContact() {


	// create a contact for the back of the list
	Contact front = { "test a", "a01234567890", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "c01234567890", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "b01234567890", "testb@gmail.com", "btesting function" };

	Node* pList = NULL; // the testing linked list

	if (!insertContactInOrder(&pList, middle)) { // insert into front
		return FALSE; // the insertion failed
	}

	if (!deleteContact(&pList, middle)) { // attempt to delete the front node
		return FALSE; // the deletion at front failed
	}

	if (!insertContactInOrder(&pList, front)) { // insert into front
		return FALSE; // the insertion failed
	}

	if (deleteContact(&pList, back)) { // attempt to delete a node that doesn't exist
		return FALSE; // the insertion succeeded unexectedly
	}

	if (!insertContactInOrder(&pList, back)) { // insert into back
		return FALSE; // the insertion failed
	}

	if (!deleteContact(&pList, back)) { // attempt to delete at back
		return FALSE; // the deletion at back failed
	}

	// test the values of front
	if (strcmp(pList->data.name, front.name) != 0 || strcmp(pList->data.phone, front.phone) != 0 ||
		strcmp(pList->data.email, front.email) != 0 || strcmp(pList->data.title, front.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	return TRUE; // if we get here, we passed all the tests and can pass the overall test
}

// ensures the functionality of editContact()
Boolean testEditContact() {

	// no implementation
	return FALSE;
}

// ensures the functionality of loadContacts()
Boolean testLoadContacts() {

	FILE* infile = fopen("testinfile.txt", "r"); // open the test input file for mode for reading

	Node* pList = NULL; // the testing linked list

	if (!loadContacts(infile, &pList)) {
		fclose(infile); // close infile
		return FALSE; // the load failed
	}

	fclose(infile); // close infile

	// create a contact for the back of the list
	Contact front = { "test a", "a01234567890", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "c01234567890", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "b01234567890", "testb@gmail.com", "btesting function" };

	// test the values of front
	if (strcmp(pList->data.name, front.name) != 0 || strcmp(pList->data.phone, front.phone) != 0 ||
		strcmp(pList->data.email, front.email) != 0 || strcmp(pList->data.title, front.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	Node* pNext = pList->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of middle
	if (strcmp(pNext->data.name, middle.name) != 0 || strcmp(pNext->data.phone, middle.phone) != 0 ||
		strcmp(pNext->data.email, middle.email) != 0 || strcmp(pNext->data.title, middle.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	pNext = pNext->pNext;
	if (pNext == NULL) {
		return FALSE; // returns false if the list was not linked properly
	}

	// test the values of back
	if (strcmp(pNext->data.name, back.name) != 0 || strcmp(pNext->data.phone, back.phone) != 0 ||
		strcmp(pNext->data.email, back.email) != 0 || strcmp(pNext->data.title, back.title) != 0) {

		return FALSE; // at least one value wasn't equal
	}

	return TRUE; // if we get here, we passed all the tests and can pass the overall test

}

// ensures the functionality of storeContacts()
Boolean testStoreContacts() {

	// create a contact for the back of the list
	Contact front = { "test a", "01234567890", "testa@gmail.com", "atesting function" };

	// create contact for the front of the list
	Contact back = { "test c", "01234567890", "testc@gmail.com", "ctesting function" };

	// create contact for initial insertion
	Contact middle = { "test b", "01234567890", "testb@gmail.com", "btesting function" };

	Node* pList = NULL; // the testing linked list

	if (!insertContactInOrder(&pList, middle)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, front)) {
		return FALSE; // the insertion failed
	}

	if (!insertContactInOrder(&pList, back)) {
		return FALSE; // the insertion failed
	}

	FILE* outfile = fopen("testoutfile.txt", "w"); // open the test output file for mode for writing

	if (!storeContacts(outfile, pList)) {
		fclose(outfile);
		return FALSE; // store failed
	}

	// close outfile and open for mode read
	fclose(outfile);
	//return 0;
	outfile = fopen("testoutfile.txt", "r");

	char temp[132]; // holds the lines of the file

	// check first line
	fgets(temp, 53, outfile);
	fgetc(outfile); // cleans the newline character
	if (strcmp(temp, "test a,01234567890,testa@gmail.com,atesting function") != 0) {
		return FALSE; // store unsuccessfull
	}

	// check first line
	fgets(temp, 53, outfile);
	fgetc(outfile); // cleans the newline character
	if (strcmp(temp, "test b,01234567890,testb@gmail.com,btesting function") != 0) {
		return FALSE; // store unsuccessfull
	}

	// check first line
	fgets(temp, 53, outfile);
	fgetc(outfile); // cleans the newline character
	if (strcmp(temp, "test c,01234567890,testc@gmail.com,ctesting function") != 0) {
		return FALSE; // store unsuccessfull
	}
	

	fclose(outfile);

	return TRUE; // if we get here, we passed all the tests and can pass the overall test
}

// ensures the functionality of printLists()
Boolean testPrintList() {

	// no implementation
	return FALSE;
}