/// Martin Hundrup
/// Cpt_122, Lab4
/// February 8, 2024
/// Defines the function prototypes for the stack testing functions

#ifndef TESTSTACK_H
#define TESTSTACK_H

#include "Stack.h"

/// <summary>
/// Tests the makeNode function
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testMakeNode();

/// <summary>
/// Tests the isEmtpy function against a empty stack
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testIsEmptyTrue();

/// <summary>
/// Tests the isEmtpy function against a non-empty stack
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testIsEmptyFalse();

/// <summary>
/// Tests the push function on an empty stack
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testPushEmpty();

/// <summary>
/// Tests the push function on a non-empty stack
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testPushFull();

/// <summary>
/// Tests the pop function on a stack with one node
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testPopEmpty();

/// <summary>
/// Tests the pop function on a stack with multiple node
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testPopFull();

/// <summary>
/// Tests the peek function on an empty stack
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testPeekEmpty();

/// <summary>
/// Tests the peek function on a non-empty stack
/// </summary>
/// <returns>TRUE if passes, FALSE if failed</returns>
Bool testPeekFull();

#endif