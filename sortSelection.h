/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    Daniel Perez, Benjamin Dyas, Jamie Hurd
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/********************************************
 * FUNCTION:  swapSelection
 * RETURNS:   void
 * PARAMETER: int iCheck, T array[]
 ********************************************/
template <class T>
void swapSelection(T * iLargest, T * iPivot)
{  
    T temp = *iLargest; // swap two items if out of order
    *iLargest = *iPivot;
    *iPivot = temp;
}

/********************************************
 * FUNCTION:    sortSelection
 * RETURNS:     void
 * PARAMETER:   int iCheck, T array[]
 * DESCRIPTION: Perform the selection sort
 ********************************************/
template <class T>
void sortSelection(T array[], int num)
{
   int iLargest = 0;

   // moves iPiviot left to right
   for (int iPivot = 0; iPivot < num - 1; iPivot++) 
   {
      iLargest = iPivot;

      // looks for the largest element
      for (int j = iPivot + 1; j < num; j++)
      {
         if (array[j] < array[iLargest])
         {
            iLargest = j;
         }
      }
      swapSelection (&array[iLargest], &array[iPivot]);
   }
}


#endif // SORT_SELECTION_H
