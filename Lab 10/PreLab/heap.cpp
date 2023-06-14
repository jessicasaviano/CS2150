
// Jessica Saviano, Jrs5xrw
// Insipired by the binary heap code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// The inspo code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include "heap.h"
#include "heapNode.h"
using namespace std;

// default constructor
heap::heap() : jess_size(0) {
    jess.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<heapNode *> vec) : jess_size(vec.size()) {
    jess = vec;
    jess.push_back(jess[0]);
    jess[0] = 0;
    for (int i = jess_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(heapNode* x) {
    // a vector push_back will resize as necessary
    jess.push_back(x);
    // move it up into the right position
    percolateUp(++jess_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    heapNode* node = jess[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (node->freq1 < jess[hole/2]->freq1); hole /= 2) {
        jess[hole] = jess[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    jess[hole] = node;
}

heapNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (jess_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    heapNode* ret = jess[1];
    // move the last inserted position into the root
    jess[1] = jess[jess_size--];
    // make sure the vector knows that there is one less element
    jess.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    heapNode* node = jess[hole];
    // while there is a left child...
    while (hole*2 <= jess_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= jess_size) && (jess[child+1]->freq1 < jess[child]->freq1)) {
            child++;
        }
        // if the child is greater than the node...
        if (node->freq1 > jess[child]->freq1) {
            jess[hole] = jess[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    jess[hole] = node;
}

heapNode* heap::findMin() {
  //find min of tree, heap doesn't know we're making a tree 
    if (jess_size == 0) {
        throw "findMin() called on empty heap";
    }
    return jess[1];
}

unsigned int heap::size() {
    return jess_size;
}

void heap::makeEmpty() {
    jess_size = 0;
    jess.resize(1);
}

bool heap::isEmpty() {
    return jess_size == 0;
}



void heap::print() {
    cout << "(" << jess[0] << ") ";
    for (int i = 1; i <= jess_size; i++) {
        cout << jess[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

