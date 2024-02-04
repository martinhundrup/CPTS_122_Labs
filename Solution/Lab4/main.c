#include "Lab4.h"
#include "TestStack.h"

int main()
{
	printf("result of testMakeNode(): %d\n", testMakeNode());
	printf("result of testIsEmptyTrue(): %d\n", testIsEmptyTrue());
	printf("result of testIsEmptyFalse(): %d\n", testIsEmptyFalse());
	printf("result of testPushEmpty(): %d\n", testPushEmpty());
	printf("result of testPushFull(): %d\n", testPushFull());
	printf("result of testPopEmpty(): %d\n", testPopEmpty());
	printf("result of testPopFull(): %d\n", testPopFull());
	printf("result of testPeekEmpty(): %d\n", testPeekEmpty());
	printf("result of testPeekFull(): %d\n", testPeekFull());

	return 0;
}