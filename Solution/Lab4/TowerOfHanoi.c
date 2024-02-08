#include "TowerOfHanoi.h"

Disk* makeDisk(double nData) {

	Disk* newDisk = (Disk*)malloc(sizeof(Disk)); // allocate and store memory for a Disk
	newDisk->size = nData; // store the passed in data in the Disk
	newDisk->pNext = NULL; // sets the next pointer to the NULL pointer

	return newDisk;
}

Bool isEmptyTower(Disk* pHead) {

	if (pHead == NULL) {

		return TRUE; // if the head pointer is NULL, the stack is empty
	}

	return FALSE; // the stack is not empty if the head pointer contains a Disk
}

Bool pushTower(Disk** pHead, double nData) {

	Disk* newDisk = makeDisk(nData);

	if (newDisk == NULL) {

		return FALSE; // ensures data was allocated successfully
	}

	if (isEmpty(*pHead)) {

		*pHead = newDisk; // if the list is empty, the new Disk becomes the head Disk
		return TRUE;
	}

	newDisk->pNext = *pHead; // the new Disk points at the head pointer
	*pHead = newDisk; // the head pointer becomes the new Disk

	return TRUE;
}

int popTower(Disk** pHead) {

	int val = 0;
	if (!isEmpty(*pHead)) { // only delete something if there is a head pointer

		val = (*pHead)->size;
		Disk* pTemp = (*pHead)->pNext; // temp data to store the next Disk
		free(*pHead); // delete the head pointer
		*pHead = pTemp; // set the new head pointer to the old next
	}

	return val;
}

int peekTower(Disk* pHead) {

	if (isEmpty(pHead)) {

		return 0; // returns a predermined value if the stack is empty
	}

	return pHead->size;
}

int peekn(Disk* pHead, int n) {

	Disk* pCur = pHead;
	while (n != 0) {

		if (pCur == NULL) { // disk doesn't exist
			return -1;
		}

		pCur = pCur->pNext;
		n--;
	}

	if (pCur == NULL) { // disk doesn't exist
		return -1;
	}

	return pCur->size;
}

void print_towers(Disk* tower1, Disk* tower2, Disk* tower3) {

	int t1 = 0, t2 = 0, t3 = 0; // indices to keep track of where we are at in the tower

	// loops for each tower, at each level
	for (int i = 5; i > 0; i--) { // loop for each possible level of the towers

		if (tower_height(tower1) >= i) {
			print_disk(peekn(tower1, t1++));
		}
		else {
			print_disk(0);
		}
		if (tower_height(tower2) >= i) {
			print_disk(peekn(tower2, t2++));
		}
		else {
			print_disk(0);
		}
		if (tower_height(tower3) >= i) {
			print_disk(peekn(tower3, t3++));
		}
		else {
			print_disk(0);
		}
		putchar('\n');
	}
	printf("|----1----||----2----||----3----|\n");
}

void print_disk(int size) {

	switch (size) {

	case 0:
		printf("          ");
		break;
		
	case 1:
		//printf("\033[31m    [1]    \033[0m");
		printf("    ");
		printf("\033[41m   \033[0m");
		printf("    ");
		break;
	case 2: 
		printf("   ");
		printf("\033[43m     \033[0m");
		printf("   ");
		break;
	case 3:
		printf("  ");
		printf("\033[42m       \033[0m");
		printf("  ");
		break;
	case 4:
		printf(" ");
		printf("\033[44m         \033[0m");
		printf(" ");
		break;
	case 5:
		printf("\033[45m           \033[0m");
		break;
	}
}


int tower_height(Disk* tower) {

	int count = 0;
	Disk* pCur = tower;
	while (pCur != NULL) { // loop through stack until end is reached
		count++;
		pCur = pCur->pNext;
	}

	return count; // return amount of Disks present in stack
}

void play_game() {

	// initialize the start of the game
	Disk* tower1 = makeDisk(5); // starting tower
	pushTower(&tower1, 4);
	pushTower(&tower1, 3);
	pushTower(&tower1, 2);
	pushTower(&tower1, 1);

	Disk* tower2 = NULL; // middle tower

	Disk* tower3 = NULL; // goal tower

	int input = 0, num_moves = 0;

	while (input == 0) {

		system("cls"); // clear the screen

		printf("number of moves: %d\n", num_moves);

		print_towers(tower1, tower2, tower3);

		if (tower_height(tower3) == 5) {
			input = 1;
			printf("\nyou win!!!\n");
			break;
		}

		printf("Type in the number coresponding to the tower to take from: ");
		scanf("%d", &input);
		getchar();
		
		int disk_size = 0;

		switch (input) {
		case 1:
			if (tower_height(tower1) <= 0) {
				printf("that tower is empty.\n");
				break;
			}
			else {
				disk_size = popTower(&tower1);
				break;
			}
		case 2:
			if (tower_height(tower2) <= 0) {
				printf("that tower is empty.\n");
				break;
			}
			else {
				disk_size = popTower(&tower2);
				break;
			}
		case 3:
			if (tower_height(tower3) <= 0) {
				printf("that tower is empty.\n");
				break;
			}
			else {
				disk_size = popTower(&tower3);
				break;
			}
		default:
			printf("that isn't a valid tower.\n");
			break;
		}

		int new_tower = 0;
		int success = 0;

		if (disk_size != 0) { // a valid tower was chosen

			printf("Type in the number coresponding to the tower to put on top of: ");
			scanf("%d", &new_tower);
			getchar();

			if (new_tower != input) { // they chose a different tower than they took from

				switch (new_tower) {
				case 1:
					if (peekTower(tower1) < disk_size && peekTower(tower1) != 0) { // can't put there
						printf("can't put larger disks on smaller ones.");
						break;
					}
					else {
						pushTower(&tower1, disk_size);
						success = 1;
						break;
					}
				case 2:
					if (peekTower(tower2) < disk_size && peekTower(tower2) != 0) { // can't put there
						printf("can't put larger disks on smaller ones.");
						break;
					}
					else {
						pushTower(&tower2, disk_size);
						success = 1;
						break;
					}
				case 3:
					if (peekTower(tower3) < disk_size && peekTower(tower3) != 0) { // can't put there
						printf("can't put larger disks on smaller ones.");
						break;
					}
					else {
						pushTower(&tower3, disk_size);
						success = 1;
						break;
					}
				default:
					printf("that isn't a valid tower.\n");
					break;
				}
			}
		}

		if (success == 0) { // put disk back on top of previous tower
			switch (input) { 
			case 1:
				pushTower(&tower1, disk_size);
				break;
			case 2:
				pushTower(&tower2, disk_size);
				break;
			case 3:
				pushTower(&tower3, disk_size);
				break;
			}
		}
		else {
			num_moves++;
		}


		input = 0;
	}
}