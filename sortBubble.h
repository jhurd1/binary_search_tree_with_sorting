/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    Daniel Perez, Benjamin Dyas, Jamie Hurd
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H


/********************************************
 * FUNCTION:  swapBubble
 * RETURNS:   void
 * PARAMETER: int iCheck, T array[]
 ********************************************/
template <class T>
void swapBubble(int iCheck, T array[])  
{  
    T temp = array[iCheck]; // swap two items if out of order
    array[iCheck] = array[iCheck + 1];
    array[iCheck + 1] = temp;
}

/********************************************
 * FUNCTION:    sortBubble
 * RETURNS:     void
 * PARAMETER:   int iCheck, T array[]
 * DESCRIPTION: Perform the bubble sort
 ********************************************/
template <class T>
void sortBubble(T array[], int num)
{
    // total number of comparisons
    int numCompare = 0;
    bool swapped = true;

    //outer loop: starts at the back and moves towards the beginning,
    //   iSpot being the division between sorted and not sorted
    for (int iSpot = num - 1; iSpot >= 1 && swapped; iSpot--)
    {
        //swapped = false;
        for (int iCheck = 0, swapped = false; iCheck <= iSpot - 1; iCheck++)
        {
            numCompare++;

            //"Bubble" the bigger value towards the end.
            if (array[iCheck] > array[iCheck + 1])
            {
                swapBubble(iCheck, array);
                swapped = true; // after swap, loop again
            }
        }
    }
}

#endif // SORT_BUBBLE_H
