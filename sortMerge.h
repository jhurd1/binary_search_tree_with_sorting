/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    Daniel Perez, Benjamin Dyas, Jamie Hurd
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H
// C++ program for Merge Sort
#include <iostream>
using namespace std;
/*****************************************************
 * SORTMERGE
 * Perform the merge sort
 ****************************************************/

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
/********************************************
* FUNCTION:  MERGE
* RETURNS:   void
* PARAMETER: T arr, int l, int m, int r
********************************************/
template <class T>
void merge(T arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	T L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) 
   {
		if ((L[i] < R[j]) || (L[i] == R[j]))
      {
			arr[k] = L[i];
			i++;
		}
		else 
      {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) 
   {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) 
   {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
/********************************************
* FUNCTION:  MERGESORT
* RETURNS:   void
* PARAMETER: T arr, int l, int r
********************************************/
template <class T>
void mergeSort(T arr[], int l, int r)
{  
	if(l >= r)
   {
		return;//returns recursively
	}
	int m = (l + r - 1) / 2;
	mergeSort (arr, l, m);
	mergeSort (arr, m+1, r);
	merge (arr, l, m, r);
}

/********************************************
* FUNCTION:  SORTMERGE
* RETURNS:   void
* PARAMETER: T array, int num
********************************************/
template <class T>
void sortMerge(T array[], int num)
{
   //int arr_size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(array, 0, num - 1);
   
}

#endif // SORT_MERGE_H
