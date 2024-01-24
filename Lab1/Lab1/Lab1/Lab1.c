#include "Lab1.h"

/*
For this first program you will only need one executable C statement to output a
message. Your program should output "Hello World, I am in CptS 122!" with a printf ( )
statement.
*/
void task_1() {
	printf("Hello World, I am in CptS 122!\n");
}

/*
Write a function that recursively reverses a string. Recall, a recursive
function is a function that calls itself. These functions have at least
one base or simple case and at least one recursive step. The base
case(s) have known solutions. As the function is called, the problem is
broken down into simpler parts that are closer to the base case.
*/
void task_2() {

	// we CAN NOT create the string this way for a true in place reverse, why?
	// if we wanted to do it this way, how would we accomplish this?
	//char* my_string = "Hello World, I am in CptS 122!";

	// but we can do this, why?
	char my_string[100] = "Hello World, I am in CptS 122!";

	printf("before reverse: %s\n", my_string); // print the contents before reversal for checking

	recursive_str_reverse(my_string); // call our reverse function - why don't we have it return a value?

	printf("after reverse: %s\n", my_string); // print the contents after reversal for checking
}

// recursively reverses a string in place
void recursive_str_reverse(char* p_string) {

	static int index = 0;

	// base case: we are at the middle of the string
	if (index == strlen(p_string) / 2) {
		return;
	}

	// swap the current indices
	char temp = p_string[index];
	p_string[index] = p_string[strlen(p_string) - index - 1];
	p_string[strlen(p_string) - index - 1] = temp;

	// recursive step
	index++;
	recursive_str_reverse(p_string);
}



/*
Write a function called myStrTok() that behaves in the following
manner (taken from http://en.cppreference.com/w/c/string/byte/strtok). 
Note: all references to strtok() should be replaced by myStrTok(). You
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
void task_3() {

	char my_string[100] = "Hello World, I am in CptS 122!";
	//char my_string[100] = "Hello World";

	printf("%s\n", my_strtok(my_string, ' ')); // I am using the space character as the delimchar my_string[100] = "Hello World, I am in CptS 122!";

	// uncomment the below line and notice that now if we print the entire string only "Hello" prints.
	// this is due to the fact that we replaced the delim (' ') with the null character
	//printf("%s\n", my_string);

	printf("%s\n", my_strtok(my_string, ' ')); // Notice that because I called the function passing in the value, it returns the same as the last call

	printf("%s\n", my_strtok(NULL, ' ')); // because we passed in NULL it continued from where we left of

	printf("%s\n", my_strtok(NULL, ' ')); // if I were to pass in a string with only two tokens, 
										  //this would return NULL, try "Hello World" and see for yourself.
}

// a custom strtok function that works with back to back delimeters
char* my_strtok(char* p_string, char delim) {

	static char* str = NULL; // the previous call's value will supercede the NULL due to the static keyword

	if (p_string != NULL) // new call
		str = p_string; // we want to start at the beginning of the provided string


	int exit_con = 0; // keeps track whether we ran into the delim (0), or end of string (1)
	
	int i = 0; // index variable
	for (i; str[i] != delim ; i++) { // loop until we encounter a delim character or a null character
		// I will exit the loop manually in the case that we run into the end of the string
		// before we reach a delim

		if (str[i] == '\0') // we reached the end of the string
			break;
	}

	// set the delim index to the null character
	str[i] = '\0';

	// set the static str pointer to the character after the delim in the case that
	// we have NOT reached the end of the string
	char* p_prev = str; // the pointer the token
	if (exit_con == 0)
		str = str + i + 1; // now str points to the rest of the string

	// return the original pointer, which is now terminted by the null character
	// where the delim used to be
	return p_prev;
}

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
void task_4() {

	// there are a number of ways to achieve this solution
	// you could concatenate the string into the desired location then sort the string
	// or you could loop through each string as you build the new one.
	// I will be going with the second approach.

	// the strings to be merged
	char str1[100] = "hello";
	char str2[100] = " world";
	char str3[100] = { '\0' };

	// print the first type of merge
	merge_1(str1, str2, str3);
	printf("first merge: %s\n", str3);

	// print the second type of merge
	printf("second merge: %s\n", merge_2(str1, str2));

	// print the third type of merge
	merge_3(str1, str2);
	printf("first merge: %s\n", str1);
}

// alphabetically merges str1 and str2 into destination
void merge_1(const char* str1, const char* str2, char* destination) {

	// there's probably a better way to go about this but this suffices
	
	int ascii_histogram[128] = { 0 }; // a histogram representing all the ascii appearances in the two strings
	int dest_counter = 0; // counts the amount of characters we've inserted into the destination string, 
						  // should never be above strlen(str1) + strlen(str2)

	for (int i = 0; i < 128; i++) { // the ascii table contains values for characters between 0 and 127
		for (int j = 0; j < strlen(str1); j++) { // loop through each char in str1
			if (str1[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
		for (int j = 0; j < strlen(str2); j++) { // loop through each char in str2
			if (str2[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
	}

	for (int i = 0; i < 128; i++) { // this loops through our histogram and inserts the amount of characters present into the destination string

		for (int j = 0; j < ascii_histogram[i]; j++) {
			destination[dest_counter] = i;
			dest_counter++;
		}
	}
	destination[dest_counter] = '\0'; // insert null character at the end
}

// alpahabetically merges str1 and str2 into a new, dynamically allocated char array
char* merge_2(const char* str1, const char* str2) {

	// the bulk of this is copied form merge_1()

	int ascii_histogram[128] = { 0 }; // a histogram representing all the ascii appearances in the two strings
	int dest_counter = 0; // counts the amount of characters we've inserted into the destination string, 
	// should never be above strlen(str1) + strlen(str2)

	for (int i = 0; i < 128; i++) { // the ascii table contains values for characters between 0 and 127
		for (int j = 0; j < strlen(str1); j++) { // loop through each char in str1
			if (str1[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
		for (int j = 0; j < strlen(str2); j++) { // loop through each char in str2
			if (str2[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
	}

	// allocate memory for the destination array as 1,
	// as we will use realloc() each time a new character is inserted
	char* destination = (char*) malloc(sizeof(char));

	// used to temporarily store the contents of realloc()
	//char* temp;

	for (int i = 0; i < 128; i++) { // this loops through our histogram and inserts the amount of characters present into the destination string

		for (int j = 0; j < ascii_histogram[i]; j++) {
			destination = (char*)realloc(destination, sizeof(char) * (dest_counter + 1)); // make sure we add one more space for the new character
			//destination = temp;
			destination[dest_counter] = i; // ignore the warning the compiler doesn't know what its talking about
			dest_counter++;
		}
	}
	destination[dest_counter] = '\0'; // insert null character at the end

	return destination;

}

// alphabetically merges str1 and str2 back into str1
void merge_3(char* str1, const char* str2) {

	// the bulk of this is copied form merge_1()

	int ascii_histogram[128] = { 0 }; // a histogram representing all the ascii appearances in the two strings
	int dest_counter = 0; // counts the amount of characters we've inserted into the destination string, 
	// should never be above strlen(str1) + strlen(str2)

	for (int i = 0; i < 128; i++) { // the ascii table contains values for characters between 0 and 127
		for (int j = 0; j < strlen(str1); j++) { // loop through each char in str1
			if (str1[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
		for (int j = 0; j < strlen(str2); j++) { // loop through each char in str2
			if (str2[j] == i)
				ascii_histogram[i]++; // add to the histogram if a character is present
		}
	}

	for (int i = 0; i < 128; i++) { // this loops through our histogram and inserts the amount of characters present into the destination string

		for (int j = 0; j < ascii_histogram[i]; j++) {
			str1[dest_counter] = i;
			dest_counter++;
		}
	}
	str1[dest_counter] = '\0'; // insert null character at the end
}