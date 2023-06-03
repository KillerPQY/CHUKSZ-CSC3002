/*
 * File: MergeSort.cpp
 * -------------------
 * This file implements the merge sort algorithm using arrays rather
 * than vectors.
 */

#include <iostream>
using namespace std;

/* Function prototypes */

void sort(int array[], int n);
void printArray(int array[], int n);

/* Test program */

int test3() {
   int array[] = { 56, 25, 37, 58, 95, 19, 73, 30 };
   sort(array, 8);
   printArray(array, 8);
   return 0;
}

/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of the vector into increasing order using
 * the merge sort algorithm, which consists of the following steps:
 *
 * 1. Copy the array into an array allocated on the stack.
 * 2. Divide the new array into two halves by manipulating the indices.
 * 3. Sort each half of the array recursively
 * 4. Merge the two halves back into the original one.
 */

// the merge function for merge sort
void merge(int array[], int a1[], int l1, int a2[], int l2) {
    int p1 = 0;
    int p2 = 0;
    int i = 0;
    while (p1 < l1 && p2 < l2) {
        if (a1[p1] < a2[p2]) {
            array[i++] = a1[p1++];
        }
        else {
            array[i++] = a2[p2++];
        }
    }
    while (p1 < l1) array[i++] = a1[p1++];
    while (p2 < l2) array[i++] = a2[p2++];
}
// merge sort function
void sort(int array[], int n) {

   //TODO
   if (n <= 1 ) return;
   int half = n/2;
   int a1[half];
   int a2[half + 1]; // consider that n may be odd
   // store the number of elements in array a1, a2
   int l1 = 0;
   int l2 = 0;
   // The first half goes to array a1 and the second half goes to array a2
   for (int i = 0; i < n; i++) {
       if (i < half) {
           a1[i] = array[i];
           ++l1;
       }
       else {
           a2[i - half] = array[i];
           ++l2;
       }
   }

   // sort a1, a2 recursively
   sort(a1, l1);
   sort(a2, l2);
   // merge a1, a2
   merge(array, a1, l1, a2, l2);
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the elements of the array on a single line with the elements
 * enclosed in braces and separated by commas.
 */

void printArray(int array[], int n) {
   cout << "{ ";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << " }" << endl;
}
