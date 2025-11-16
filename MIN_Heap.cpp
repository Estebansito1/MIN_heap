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

            if (heap[parent] > heap[index]) // if parent > child = violates heap min
                {
                    swap(heap[parent], heap[index]); // swap them
                index = parent; // move up
                } else break; // everything is good stop
            }
    }

// move the new root down the tree after removal
    void heapifyDown(vector<int>& heap, int index)
    {
        int size = heap.size();

        while (true) // loop while conditon is true
            {
                int left = 2*index+1; //left child index
                int right = 2*index+2; // right child index
                int smallest=index; // assume the current index is smallest

            // choose the smallest if it exists
            if (left <size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] <heap[smallest]) smallest = right;

            if (smallest != index) //if parent is smaller than parent
                {
                    swap(heap[index], heap[smallest]); // swap downwards
                index = smallest; // continue heapifying
                }
            else break; // no more vialations = everything is correct
            }
    }
//////////

// insert a value into the heap
    void insertHeap(vector<int>& heap, int val)
    {
        heap.push_back(val); // add value at the end
        heapifyUp(heap, heap.size() -1); //restore heap upward
    }

// remove the minimum value
    void removeMin(vector<int>& heap)
    {
        if (heap.empty()) return;

        heap[0] = heap.back(); // move last element to root
        heap.pop_back(); // remove last element
        heapifyDown(heap, 0); // restore heap downward
    }

//print the heap as an array
    void printHeap(const vector<int>& heap)
    {
        for (int v : heap) cout << v<<" ";
        cout << endl;
    }

// the main program
    int main()
    {
        vector<int> heap = {10,15,20,17,25,30}; // initial min heap
        cout << "Initial heap: ";
        printHeap(heap);

        cout<< "After insertion 5:\n";
        insertHeap(heap, 5); // insert new smallest element
        printHeap(heap);

        cout<<"After removing min 5:\n";
        removeMin(heap); // remove top element
        printHeap(heap);
    }



























