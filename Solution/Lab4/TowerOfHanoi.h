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
/// Prints the three towers to the screen.
/// </summary>
/// /// <param name="tower1">The pointer to the left-most tower.</param>
/// /// <param name="tower2">The pointer to the middle tower.</param>
/// /// <param name="tower3">The pointer to the right-most tower.</param>
void print_screen(Disk* tower1, Disk* tower2, Disk* tower3);