// ch9searchingBenchmarks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// prototypes for functions
int linearSearch(const vector<int>&, int);
int binarySearch(const vector<int>&, int);	// binary search
int numberOfComparisons = 0;	// number of comparisons

int main()
{
    std::cout << "Chapter 9 Search Benchmarks by Kevin Bell\n\n";
	// array with 100 integer elements
	int array[100];
	// initialize array with values 0-100
	for (int i = 0; i < 100; i++)
		array[i] = i;
	// create vector from array
	vector<int> vec(array, array + 100);
	
	
	// search for middle
	cout << "Searching for value in the middle of the array, 49" << endl;
	int key = 49;
	// linear search
	int index = linearSearch(vec, key);
	cout << "Linear search made " << numberOfComparisons << " comparisons." << endl;
	// binary search
	index = binarySearch(vec, key);
	cout << "Binary search made " << numberOfComparisons << " comparisons." << endl;
	
	// search for low
	cout << "\nSearching for value at the beginning of the array, 3" << endl;
	key = 3;
	// linear search
	index = linearSearch(vec, key);
	cout << "Linear search made " << numberOfComparisons << " comparisons." << endl;
	// binary search
	index = binarySearch(vec, key);
	cout << "Binary search made " << numberOfComparisons << " comparisons." << endl;
	
	// search for high
	cout << "\nSearching for value at the end of the array, 99" << endl;
	key = 99;
	// linear search
	index = linearSearch(vec, key);
	cout << "Linear search made " << numberOfComparisons << " comparisons." << endl;
	// binary search
	index = binarySearch(vec, key);
	cout << "Binary search made " << numberOfComparisons << " comparisons." << endl;
	system("pause");
	return 0;
} // end main

// function to perform a linear search on an array and returns the count of numberOfComparisons
int linearSearch(const vector<int>& items, int key)
{
	numberOfComparisons = 0;
	for (int i = 0; i < items.size(); i++)
	{
		numberOfComparisons++;
		if (items[i] == key)
			return i;
	}
	return -1;
} // end function linearSearch

// function to perform a binary search on an array and returns the count of numberOfComparisons
int binarySearch(const vector<int>& items, int key)
{
	numberOfComparisons = 0;
	int low = 0;
	int high = items.size() - 1;
	int middle;
	while (high >= low)
	{
		middle = (low + high) / 2;
		numberOfComparisons++;
		if (key < items[middle])
			high = middle - 1;
		else if (key == items[middle])
			return middle;
		else
			low = middle + 1;
	}
	return -low - 1;
} // end function binarySearch