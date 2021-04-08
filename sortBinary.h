/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Daniel Perez, Benjamin Dyas, Jamie Hurd
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   custom::BST<T> tree;

   //create the tree, the insert method does the sorting
   for(int i = 0; i < num; i++)
   {
      tree.insert(array[i]);
   }

   //copy the sorted tree back into the array
   int j = 0;
   typename custom::BST<T>::iterator it;
   for (it = tree.begin(); it != tree.end(); it++, j++)
      array[j] = *it;
}

#endif // SORT_BINARY_H
