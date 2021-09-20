//
// Created by Varick Erickson 2/3/2021.
//

#ifndef CHUNKLIST_H
#define CHUNKLIST_H

#include <iostream>

using namespace std;

const int ARRAY_SIZE = 8;

// These error classes are done. No modifications are required.
// See ChunkList_driver.cpp for an example of how they are used.
class InvalidArrayLength{
public:
    string Msg() {
        return "Invalid array length used for constructor.";
    }
};

class IndexOutOfBounds {
public:
    string Msg() {
        return "Index is out of bounds";
    }
};

class IteratorOutOfBounds {
public:
    string Msg() {
        return "Iterator is out of bounds.  Nothing left to iterate over.";
    }
};

    class EmptyList {
public:
    string Msg() {
        return "List is empty";
    }
};

// Put your pre/post conditions here.

template<class T>
class ChunkList {
public:
    // Constructors
    /* Function: Creates an ChunkList object and takes in no arguments in the parameters
    * Precondition: None
    * Postcondition: A ChunkList object will be created
    */
    ChunkList();
    /* Function: Creates an ChunkList object and takes an array and array length
    * Precondition: The array length must be greater than 0
    * Postcondition: A ChunkList object will be created
     * The function throws an "Invalid array length" error if an invalid array length has been inputted
    */
    ChunkList(T arr[], int arrLen);

    /* Function: Destroys the ChunkList object
    * Precondition: None
    * Postcondition: The ChunkList object will be destroyed
    */
    ~ChunkList();

    // Add/remove elements
    /* Function: Appends a value to the end of the list
    * Precondition: List must not be full
    * Postcondition: The value will be added to the end of the list
    */
    void Append(T value);
    /* Function: Finds the first instance of a value and removes it from the list
    * Precondition: List must not be empty
    * Postcondition: The value will be added to the end of the list
     * Function throws a "List is empty" error if list is empty
    */
    void Remove(T value);

    // Stuff to find out about the ChunkList
    /* Function: Gets the length of the list
    * Precondition: None
    * Postcondition: The length of the list will be returned
    */
    int GetLength();
    /* Function: Gets the percentage of the ChunkList that is storing items
    * Precondition: List must not be empty
    * Postcondition: The load factor of the ChunkList is returned
     * Function throws a "List is empty" error if list is empty
    */
    double LoadFactor();
    /* Function: Returns true if the value exists in the list
    * Precondition: List must not be empty
    * Postcondition: Returns a boolean value on whether or not the value exists in the list
     * Function throws a "List is empty" error if list is empty
    */
    bool Contains(T value);

    // Accessing elements
    /* Function: Returns the index of value i in the ChunkList
    * Precondition: List must not be empty and index must be in bounds
    * Postcondition: Returns the value at index i
     * Function throws a "List is empty" error if list is empty
     * Function throws an "Index is out of bounds" error if the index is out of bounds
    */
    T GetIndex(int i);
    /* Function: Sets the iterator to the first index of the first node in the ChunkList
    * Precondition: None
    * Postcondition: The iterator will be set to the first index of the first node in the ChunkList
    */
    void ResetIterator();
    /* Function: Returns the current item and moves position to the next item in the list
    * Precondition: The next item must exist when user tries to get an item
    * Postcondition: Returns the item
     * Throws an "Iterator is out of bounds.  Nothing left to iterate over" error if there are no more items to iterate over in the ChunkList
    */
    T GetNextItem();

    /* Function: Checks whether the list is empty
     * Precondition: None
     * Postcondition: Returns a boolean value on whether or not the list is empty
     */
    bool IsEmpty();
private:

    // Note we did not need to make this a template
    // since this struct is part of a template class.
    struct Node {
        Node* next;
        int len;
        T values[ARRAY_SIZE];
    };

    Node* head;
    Node* tail;

    // iterator
    Node* iterNode;     // What node are were currently on?
    int arrPos;         // Within the node, what element are we looking at?

    int listLen;        // Total elements
    int numChunks;      // Total chunks/nodes
};

#include "ChunkList.cpp"

#endif //CHUNKLIST_H
