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
    // attempt to add value to the end of the list
    // if the array within the node is full, make a new node
    // check if head/tail is null??
    // if tail doesnt exist, create a new node and have tail point to it?
    if (!tail) {
        Node* newNode = new Node(); {
            tail = newNode;
            newNode->values[0] = value;
            // book keeping
            ++tail->len;
            ++listLen;
            ++numChunks;
            return;
        }
    }

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
    // function should find the first instance of value and remove it from the list
    // must preserve the order of list when removing
    // throw an emptyList() error if list is empty
    // edgecases: if head/tail is null, removing from beginning (of array/node), removing from end (of array/node), removing from middle (of array/node),
    // removing from the tail when tail only has one element, removing from head if head only has one element,
    // removing from any node if it only has one element, be sure to relink nodes if necessary, should not have any empty nodes in list

    if (listLen == 0) {
        throw EmptyList();
    }

    Node* curr = head;
    Node* prev = nullptr;
    bool found = false;
    int location;
    // search through array in curr node, if value not found, move on to next node
    while (!curr) {
        for (location = 0; location < curr->len; location++) {
            if (curr->values[location] == value) {
                // at this point, value is found at location
                found = true;
                break;
            }
        }
        if (found) {
            // shift elements, preserve order
            for (int i = location; i < curr->len - 1; i++) {
                curr->values[i] = curr->values[i + 1];
            }
            // book keeping
            --curr->len;
            --listLen;
            // this if statement will check if the node's array is empty and do any necessary relinking
            if (curr->len == 0) {
                // if the array in the head is empty, relink head
                if (curr == head) {
                    head = head->next;
                    delete curr;
                    --numChunks;
                    return;
                }
                // if the array in the tail is empty, relink tail by setting to prev
                if (curr == tail) {
                    tail = prev;
                    delete curr;
                    --numChunks;
                    return;
                }
                // if array in any of the middle nodes are empty, relink, delete empty node
                prev->next = curr->next;
                delete curr;
                --numChunks;
                return;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
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
    // returns the percentage of the chunkList is actually storing items
    // throw emptyList() error if list is empty
    if (listLen == 0) {
        throw EmptyList(); // ??????? syntax
    }
    double result = listLen/(numChunks*ARRAY_SIZE);
    return result;
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


