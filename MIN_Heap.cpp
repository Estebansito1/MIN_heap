/*this program demonstrates how a mini heap works.
 *A min heap keeps the smallest value at the root using an array.
 *Insertion places a new value at the end, the fixes the head using heapify up.
 *Removing the minimun replaces the root with the last element, then uses
 *heapify down. THe program show how the heap changes after each operation.
 *
 */

#include <iostream> // used for printing outputs
#include <vector> // used for dynamic array = heap
#include <algorithm> // used for swap
using namespace std; // so i dont have to use std:: everytime

// move the new value up the tree until heap property is restore
    void heapifyUp(vector<int>& heap, int index)
    {
        while (index > 0) // stop when we reach the first elemet
            {
            int parent = (index - 1) / 2; //find the parent possition
            }
    }