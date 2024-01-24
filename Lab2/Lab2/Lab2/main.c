#include "Lab2.h"

int main() {

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

			printf("\please enter the contact name: ");
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

			printf("\please enter the contact name: ");
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

	return 0;
}