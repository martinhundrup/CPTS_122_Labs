/// Martin Hundrup
/// Cpt_122, Lab4
/// February 8, 2024
/// Defines the function prototypes for the tower of hanoi game

#ifndef TOWER_H
#define TOWER_H

#include "Stack.h"

#endif

/// <summary>
/// Contains the size of the disk and the pointer to the next disk.
/// </summary>
typedef struct disk {

	int size;
	struct disk* pNext; // the disk directly below this one
} Disk;

/// <summary>
/// Allocates memory for a new disk and initializes it.
/// </summary>
/// <param name="nData">: the data to store into the disk.</param>
/// <returns>A pointer to the newly allocated disk.</returns>
Disk* makeDisk(double nData);

/// <summary>
/// Determines if a tower is empty or not.
/// </summary>
/// <param name="pHead">: a pointer to the head of a tower.</param>
/// <returns>TRUE if empty, FALSE if not empty.</returns>
Bool isEmptyTower(Disk* pHead);

/// <summary>
/// Inserts a disk onto the top of the tower.
/// </summary>
/// <param name="pHead">: a double pointer to the head of the tower.</param>
/// <param name="nData">: the data to store into the disk.</param>
/// <returns>TRUE if data was successfully allocated, FALSE otherwise.</returns>
Bool pushTower(Disk** pHead, double nData);

/// <summary>
/// Deletes the top disk of the tower.
/// </summary>
/// <param name="pHead">: a double pointer to the head of the tower.</param>
/// <returns>The data located at the top of the tower.</returns>
int popTower(Disk** pHead);

/// <summary>
/// Returns the data in the head disk of the tower.
/// </summary>
/// <param name="pHead">: a pointer to the head of the tower.</param>
/// <returns>The data stored in the top disk.</returns>
int peekTower(Disk* pHead);

/// <summary>
/// Returns the data at index n of the tower.
/// </summary>
/// <param name="pHead">a pointer to the top of the tower.</param>
/// <param name="n">the index of the disk.</param>
/// <returns>The data stored at that index or -1 if out of bounds.</returns>
int peekn(Disk* pHead, int n);

/// <summary>
/// Prints the three towers to the screen.
/// </summary>
/// <param name="tower1">The pointer to the left-most tower.</param>
/// <param name="tower2">The pointer to the middle tower.</param>
/// <param name="tower3">The pointer to the right-most tower.</param>
void print_towers(Disk* tower1, Disk* tower2, Disk* tower3);

/// <summary>
/// Prints the disk of a specified size.
/// </summary>
/// <param name="size">The size of the disk to be printed.</param>
void print_disk(int size);

/// <summary>
/// Returns the height of a tower.
/// </summary>
/// <param name="tower">The pointer to the tower.</param>
/// <returns>The amount of disks on the tower.</returns>
int tower_height(Disk* tower);

void play_game();