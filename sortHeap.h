/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    Daniel Perez, Benjamin Dyas, Jamie Hurd
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H

namespace custom
{
   /********************************************
    * CLASS: HEAP
    ********************************************/
   template <class T>
   class Heap
   {
      public:
         //constructor
         Heap(T array[], int num);
         ~Heap() {delete [] array;}

         // standard HEAP interfaces
         void sort();
         T    getMax();
         void deleteMax();
         void copyArray(T arrayToCopy[]);
         
      private:
         int num;
         void percolateDown(int index);
         void swap (int & i1, int & i2);
         T  * array;
   };

/********************************************
 * CONSTRUCTOR: HEAP
 * PARAMETER:   array, array size
 ********************************************/
   template <class T>
   Heap<T>::Heap(T arrayInput[], int num)
   {
      //dynamically allocated to avoid stack smashing
      this->array = new T[num];
      
      //copy the received array into local array
      std::copy(arrayInput, arrayInput+num, this->array);
      this->num = num;

      //equivalent to heapify or turning an array into a heap
      for(int index = num / 2; index >= 0; index--)
      {
         //the process of "pushing down" the smalles values
         //   to fulfill the heap rules
         percolateDown(index);
      } 
   }
   
/********************************************
 * FUNCTION:  PERCOLATEDOWN
 * RETURNS:   void
 * PARAMETER: int iCheck, T array[]
 ********************************************/
   template <class T>
   void custom::Heap<T>::percolateDown(int index)
   {
      //Find the index that represents a child of a node in the heap
      //   but in the array version of a heap
      int indexLeft = index * 2 + 1; //MIGHT BE AN ERROR IN THE PSEUDO CODE!!!
      int indexRight = indexLeft + 1;

      //if the right child is bigger than the parent and the left child
      if (indexRight <= num && 
          array[indexRight] > array[indexLeft]&& 
          array[indexRight] > array[index])
      {
          swap (index, indexRight);
          percolateDown (indexRight);
      }
      //if the left child is bigger than the parent and the right child
      else if (indexLeft <= num && array[indexLeft] > array[index])
      {
          swap (index, indexLeft);
          percolateDown (indexLeft);
      }
   }

   /********************************************
    * FUNCTION:  SORT
    * RETURNS:   void
    * PARAMETER: N/A
    ********************************************/
   template <class T>
   void custom::Heap<T>::sort()
   {
      //holds the sorted value
      T finalArray[num];
      int finalNum = num;
           
      while (num > 0)
      {
         //the swap function swaps by using references, these variables
         //  prevent the reference to an r-value issue
         int arrayHead = 0;
         int lastIndex = num - 1;
         swap (arrayHead, lastIndex);
         num--;
         
         //save the bigger value to a new array
         finalArray[lastIndex] = array[lastIndex];

         //to prevent the swapped value to be percolated
         //  and at the same time avoiding copying the whole array
         //  into a new one.
         array[lastIndex] = '\0'; 

         percolateDown (arrayHead);
      }
      
      //bring back the values into the array member of the heap
      this->num = finalNum;
      std::copy(finalArray, finalArray+finalNum, this->array);
      
   }
   
   /********************************************
    * FUNCTION:  SWAP
    * RETURNS:   void
    * PARAMETER: int & i1, int & i2
    ********************************************/
   template <class T>
   void custom::Heap<T>::swap(int & i1, int & i2)
   {
      //standard swap
      T temp = this->array[i1];
      this->array[i1] = this->array[i2];
      this->array[i2] = temp;

   }

   /********************************************
    * FUNCTION:  COPYARRAY
    * RETURNS:   void
    * PARAMETER: array[]
    ********************************************/
   template <class T>
   void Heap<T>::copyArray(T arrayToCopy[])
   {
      std::copy(this->array, array + num, arrayToCopy);
   }

} // namespace custom

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
void sortHeap(T array[], int num)
{
   custom::Heap<T> h (array, num);
   h.sort();
   h.copyArray(array);
}
#endif // SORT_HEAP_H
