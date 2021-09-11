//
// Your code here
//
template<class T>
ChunkList<T>::ChunkList() {
    head = nullptr;
    tail = nullptr;
    iterNode = nullptr;
}

template<class T>
ChunkList<T>::ChunkList(T *arr, int arrLen) {

}

template<class T>
ChunkList<T>::~ChunkList() {
    // deallocates memory
    while (!head) {
        Node* curr = head;
        head = head->next;
        delete curr;
    }
}

template<class T>
void ChunkList<T>::Append(T value) {
    // check if head/tail is null??

    // attempt to add value to the end of the list
    // if the array within the node is full, make a new node

    // check if the array is full in the tail node
    if (tail->listLen == ARRAY_SIZE) { // tail->listLen returns the size of the array in the tail?
        // make a new node
        Node* newNode = new Node(); // or Node* newNode;
        // set newNode to tail
        tail = newNode;
        // put in value into the array at first index
        newNode->values[0] = value;
        // book keeping
        ++tail->len;
        ++listLen;
        ++numChunks;
        return;
    }
    // at this point, array in tail node is not full so put the element in the end of the array
    tail->values[listLen-1] = value;
}

template<class T>
void ChunkList<T>::Remove(T value) {

}

template<class T>
int ChunkList<T>::GetLength() {
    int length = 0;
    // if head is null then there are no elements in the linked list
    if (!head) {
        return length;
    }
    Node* curr = head;
    while (!curr) {
        // iterate through the linked list and count the number of elements
        length = length + listLen;
        curr = curr->next;
    }
    return length;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    return 0;
}

template<class T>
bool ChunkList<T>::Contains(T value) {
    if (!head) {
        return false;
    }
    Node* curr = head;
    // this while loop will iterate through the linked list
    while (!curr) {
        // this for loop will iterate through the array within the node
        for (int i = 0; i < listLen; i++) {
            if (curr->values[i] == value) {
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}

template<class T>
T ChunkList<T>::GetIndex(int i) {
    return nullptr;
}

template<class T>
void ChunkList<T>::ResetIterator() {

}

template<class T>
T ChunkList<T>::GetNextItem() {
    return nullptr;
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    return false;
}

#include "ChunkList.h"


