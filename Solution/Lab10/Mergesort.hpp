#include "Lab10.hpp"

template <class T>
class Mergesort {

public:

	/// <summary>
	/// Default constructor; overloaded not needed.
	/// </summary>
	Mergesort() {};

	/// <summary>
	/// Prints an array.
	/// </summary>
	/// <param name="array">The array to print.</param>
	/// <param name="size">The number of elements in the array.</param>
	void printArray(T* array, int size)
	{
		for (int i = 0; i < size; i++) {

			std::cout << array[i] << " ";
		}

		std::cout << std::endl;
	}

	/// <summary>
	/// Public interface for sorting.
	/// </summary>
	/// <param name="array">The array to be sorted.</param>
	/// <param name="size">The number of elements in the array.</param>
	void sort(T* array, int size) {

		sort(array, 0, size - 1);
	}


private:

	/// <summary>
	/// Performs an in-place merge sort on an array.
	/// </summary>
	/// <typeparam name="T">The data type contained in the array.</typeparam>
	/// <param name="array">Pointer to the start of the array.</param>
	/// <param name="start">The index of the start of the array.</param>
	/// <param name="end">The indec of the end of the array.</param>
	void sort(T array[], int start, int end) {

		if (start < end) {

			int middle = start + (end - start) / 2;

			sort(array, start, middle);
			sort(array, middle + 1, end);

			mergeArrays(array, start, middle, end);
		}
	}

	/// <summary>
	/// Merges two sorted subarrays back into the original.
	/// </summary>
	/// <param name="array">The entire array being sorted.</param>
	/// <param name="left">The left index of the array.</param>
	/// <param name="middle">The lower middle index of the array.</param>
	/// <param name="right">The right index of the array.</param>
	void mergeArrays(T array[], int left, int middle, int right) {

		int subArray1Length = middle - left + 1;
		int subArray2Length = right - middle;

		// create temp arrays for the merger (this is required)
		T* leftSubArray = new T[subArray1Length];
		T* rightSubArray = new T[subArray2Length];

		// create copies of sub arrays
		for (int i = 0; i < subArray1Length; i++) {

			leftSubArray[i] = array[left + i];
		}
		for (int i = 0; i < subArray2Length; i++) {

			rightSubArray[i] = array[middle + 1 + i];
		}

		int i = 0; // keeps track of current index in left array
		int j = 0; // keeps track of current index in right array
		int k = left; // keeps track of current index in original array

		// read from temp arrays into the original array in ascending order
		while (i < subArray1Length && j < subArray2Length) {

			if (leftSubArray[i] <= rightSubArray[j]) {

				array[k++] = leftSubArray[i++];
			}
			else {

				array[k++] = rightSubArray[j++];
			}
		}

		// note: only one or the other will run
		while (i < subArray1Length) { // finish reading in any leftover left array contents

			array[k++] = leftSubArray[i++];
		}
		while (j < subArray2Length) { // finish reading in any leftover right array contents

			array[k++] = rightSubArray[j++];
		}

		// delete the temp arrays
		delete[] leftSubArray;
		delete[] rightSubArray;
	}
};