#ifndef LAB1_H
#define LAB1_H

#include <stdio.h>
#include <string.h> // used ONLY for strlen()
#include <stdlib.h> // used for realloc()

/*
For this first program you will only need one executable C statement to output a
message. Your program should output "Hello World, I am in CptS 122!" with a printf ( )
statement.
*/
void task_1();


/*
Write a function that recursively reverses a string. Recall, a recursive
function is a function that calls itself. These functions have at least
one base or simple case and at least one recursive step. The base
case(s) have known solutions. As the function is called, the problem is
broken down into simpler parts that are closer to the base case.
*/
void task_2();

// recursively reverses a string in place
void recursive_str_reverse(char* p_string);

/*
Write a function called myStrTok() that behaves in the following
manner (taken from
http://en.cppreference.com/w/c/string/byte/strtok). Note: all
references to strtok() should be replaced by myStrTok(). You
will need to declare a static pointer inside of myStrTok() to track
tokens through successive calls!!!
Finds the next token in a null-terminated byte string pointed to by str.
The separator characters are identified by null-terminated byte string
pointed to by delim. This function is designed to be called multiples times
to obtain successive tokens from the same string.
	- If str != NULL, the call is treated as the first call to strtok for this
	particular string. The function searches for the first character which
	is not contained in delim.
	- If no such character was found, there are no tokens in str at all, and
	the function returns a null pointer.
	- If such character was found, it is the beginning of the token. The
	function then searches from that point on for the first character
	that is contained in delim.
	- If no such character was found, str has only one token, and future
	calls to strtok will return a null pointer
	- If such character was found, it is replaced by the null
	character '\0' and the pointer to the following character is stored in
	a static location for subsequent invocations
	- The function then returns the pointer to the beginning of the token
	- If str == NULL, the call is treated as a subsequent calls
	to strtok: the function continues from where it left in previous
	invocation. The behavior is the same as if the previously stored
	pointer is passed as str. The behavior is undefined if
	either str or delim is not a pointer to a null-terminated byte string
*/
void task_3();

// a custom strtok function that works with back to back delimeters
char* my_strtok(char* p_string, char delim);

/*
Write a function that integrates or merges two unsorted strings into
sorted order. You will need to provide multiple solutions.
	i. Solution 1: Merge items into a third, fixed-sized array.
	ii. Solution 2: Merge items into a third, dynamically allocated
	array, which grows as each item is inserted. Consider using
	realloc(). You will find more information about realloc()
	at: http://en.cppreference.com/w/c/memory/realloc. We are
	NOT using a linked list to solve this problem!!!
	iii. Solution 3: Merge items without the use of a third array.
*/
void task_4();

// alphabetically merges str1 and str2 into destination
void merge_1(const char* str1, const char* str2, char* destination);

// alpahabetically merges str1 and str2 into a new, dynamically allocated char array
char* merge_2(const char* str1, const char* str2);

// alphabetically merges str1 and str2 back into str1
void merge_3(char* str1, const char* str2);

#endif
