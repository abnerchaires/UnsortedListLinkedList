#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currentPos = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return length >= MAX_ITEMS;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {

    Node* curr = head;

    while (curr != nullptr) {

        if (curr->info == someItem) {
            return true;
        }

        curr = curr->next;
    }

    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {

    // Construct a new node.
    Node* newNode = new Node;
    newNode->info = item;
    newNode->next = head;

    head = newNode;

    ++length;   // Big O notation will always be 0(1) for an unsorted linked list.

}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {

    Node* curr = head;
    Node* prevNode = nullptr;

    while (curr != nullptr) {

        if (curr->info == item) {
            if (prevNode != nullptr)
            {
                prevNode->next = curr->next;
            }
            else
            {
                head = head->next;
            }
            delete curr;
            --length;
            return;
        }
        prevNode = curr;
        curr = curr->next;
    }

}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currentPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {

    if (currentPos == nullptr) {
        throw "No elements left in iterator.";
    }

    T currentItem = currentPos->info;

    currentPos = currentPos->next;
    return currentItem;
}
