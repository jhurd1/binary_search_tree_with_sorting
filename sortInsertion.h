/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    Daniel Perez, Benjamin Dyas, Jamie Hurd
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/****************************************************
* BINARY SEARCH
****************************************************/
template <class T>
int binarySearch (T array[], T search, int iBegin, int iEnd)
{
    //start at the middle
    int iMiddle = (iBegin + iEnd) / 2;

    //recursive binary search
    if (iBegin > iEnd)
    {
        return iBegin;
    }
    if (array[iMiddle] == search)
    {
        return iMiddle;
    }
    if (search > array[iMiddle])
    {
        return binarySearch (array, search, iMiddle + 1, iEnd);
    } else 
    {
        return binarySearch (array, search, iBegin, iMiddle - 1);
    }
    return 0;
}


/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num) // i = iPivot   key = valuePiviot    j = iShift
{
    //traverse the array to be sorted
    for(int iPivot = num - 2; iPivot >= 0; iPivot--)
    {
        T valuePivot = array[iPivot];

        //the value to be inserted is the result of iInsert
        int iInsert = binarySearch(array, valuePivot, iPivot + 1, num - 1);
        iInsert--;
        int iShift = iPivot;

        //shift values left
        for(; iShift < iInsert; iShift++)
        {
            array[iShift] = array[iShift + 1];
        }
        
        //insert new value after the shifting.
        array[iShift] = valuePivot;
    }
}

#endif // SORT_INSERTION_H
