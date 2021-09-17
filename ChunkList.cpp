//
// Your code here
//
template<class T>
ChunkList<T>::ChunkList() {
    head = nullptr;
    tail = nullptr;
    listLen = 0;
    iterNode = nullptr;
    arrPos = 0;
    numChunks = 0;
}

template<class T>
ChunkList<T>::ChunkList(T arr[], int arrLen) {
    head = nullptr;
    tail = nullptr;
    //listLen = arrLen;
    listLen = 0;
    iterNode = nullptr;
    arrPos = 0;
    numChunks = 0;
    if (arrLen < 0) {
        throw InvalidArrayLength();
    }
    for (int i = 0; i < arrLen; i++) {
        // book keeping is done within the append function
        Append(arr[i]);
    }
    // at this point, the list has been created
    // initialize the iterator to start at the beginning of the list
    iterNode = head;
    arrPos = 0;
}

template<class T>
ChunkList<T>::~ChunkList() {
    // deallocates memory
    while (head) {
        Node* curr = head;
        head = head->next;
        delete curr;
    }
    head = nullptr;
    tail = nullptr;
    listLen = 0;
    iterNode = nullptr;
    arrPos = 0;
    numChunks = 0;
}

template<class T>
void ChunkList<T>::Append(T value) {
    // attempt to add value to the end of the list
    // if the array within the node is full, make a new node
    Node* newNode = nullptr;
    if (head == nullptr) {
        newNode = new Node();
        // tail and head pointing to the same node since there is only one node in the list at the moment
        tail = newNode;
        head = newNode;
        head->next = nullptr;
        head->values[0] = value;
        // book keeping
        ++tail->len;
        ++listLen;
        ++numChunks;
        return;

        // check if the array is full in the tail node
    } else if (tail->len == ARRAY_SIZE) { // tail->len returns the size of the array in the tail?
        // make a new node
        newNode = new Node();
        // relink
        tail->next = newNode;
        // set newNode to tail
        tail = newNode;
        tail->next = nullptr;
        // put in value into the array at first index
        tail->values[0] = value;
        // book keeping
        ++tail->len; // length of new tail is now 1
        ++listLen;
        ++numChunks;
        return;
    }

    // at this point, array in tail node is not full so put the element in the end of the array
    //tail->values[(tail->len)-1] = value;
    tail->values[tail->len] = value;
    // book keeping
    ++listLen;
    ++tail->len;

}

template<class T>
void ChunkList<T>::Remove(T value) {
    // function should find the first instance of value and remove it from the list
    // must preserve the order of list when removing
    // throw an emptyList() error if list is empty
    // edgecases: if head/tail is null, removing from beginning (of array/node), removing from end (of array/node), removing from middle (of array/node),
    // removing from the tail when tail only has one element, removing from head if head only has one element, removing from any node if it only has one element
    // relink nodes if necessary, should not have any empty nodes in list

    if (listLen == 0) {
        throw EmptyList();
    }

    Node* curr = head;
    Node* prev = nullptr;
    bool found = false;
    int location;
    // search through array in curr node, if value not found, move on to next node
    while (curr != nullptr) {
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
                    tail->next = nullptr; // if you do not set tail->next to nullptr, tail->next could be pointing to a garbage value
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
    return listLen;
}

template<class T>
double ChunkList<T>::LoadFactor() {
    // returns the percentage of the chunkList is actually storing items
    if (listLen == 0) {
        throw EmptyList();
    }
    double result = (double)listLen/(numChunks*ARRAY_SIZE);
    return result;
}

template<class T>
bool ChunkList<T>::Contains(T value) {
    if (head == nullptr) {
        return false;
    }
    Node* curr = head;
    // this while loop will iterate through the linked list
    while (curr != nullptr) {
        // this for loop will iterate through the array within the node
        for (int i = 0; i < curr->len; i++) {
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
    // if list is empty, throw error
    if (listLen == 0) {
        throw EmptyList();
    }

    // if index provided is out of bounds, throw error
    if (i < 0 || i >= listLen) { //
        throw IndexOutOfBounds();
    }

    Node* curr = head;
    while (!curr) {
        if (curr->len < i) {
            return curr->values[i];
        }
        // at this point, index provided cannot be found in current node
        i = i - curr->len;
        curr = curr->next;
    }
}

template<class T>
void ChunkList<T>::ResetIterator() {
    iterNode = head;
    arrPos = head->values[0];
}

template<class T>
T ChunkList<T>::GetNextItem() {
    if (arrPos >= listLen) {
        throw IteratorOutOfBounds();
    }
    arrPos++;
    if (arrPos > iterNode->len - 1) {
        iterNode = iterNode->next;
    }
    return iterNode->values[arrPos];
}

template<class T>
bool ChunkList<T>::IsEmpty() {
    bool result = false;
    if (listLen > 0) {
        result = true;
    }
    return result;
}

#include "ChunkList.h"



