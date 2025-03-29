#ifndef FLEXLL_CPP
#define FLEXLL_CPP

#include "FlexLL.h"
#include <algorithm>

template <typename T>
FlexLL<T>::FlexLL() : head(nullptr), tail(nullptr), iterate(nullptr), size(0) {}


template <typename T>
FlexLL<T>::~FlexLL() {
    flush();
}

template <typename T>
FlexLL<T>::FlexLL(const FlexLL<T>& other) : head(nullptr), tail(nullptr), iterate(nullptr), size(0) {
    copyFrom(other);
}


template <typename T>
FlexLL<T>& FlexLL<T>::operator=(const FlexLL<T>& other) {
    if (this != &other) {
        flush();
        copyFrom(other);
    }
    return *this;
}

// helper: deep copy
template <typename T>
void FlexLL<T>::copyFrom(const FlexLL<T>& other) {
    FlexLLNode<T>* curr = other.head;
    while (curr) {
        append(curr->data);
        curr = curr->next;
    }
}

template <typename T>
bool FlexLL<T>::empty() const {
    return size == 0;
}

template <typename T>
bool FlexLL<T>::flush() {
    FlexLLNode<T>* curr = head;
    while (curr) {
        FlexLLNode<T>* next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = iterate = nullptr;
    size = 0;
    return true;
}

template <typename T>
bool FlexLL<T>::prepend(const T& value) {
    FlexLLNode<T>* newnode = new FlexLLNode<T>(value);
    newnode->next = head;
    if (head) head->prev = newnode;
    else tail = newnode;
    head = newnode;
    size++;
    return true;
}

template <typename T>
bool FlexLL<T>::append(const T& value) {
    FlexLLNode<T>* newnode = new FlexLLNode<T>(value);
    newnode->prev = tail;
    if (tail) tail->next = newnode;
    else head = newnode;
    tail = newnode;
    size++;
    return true;
}

template <typename T>
bool FlexLL<T>::sort() {
    if (size <= 1) return true;
    bool sorted = true;
    for (FlexLLNode<T>* i = head; i; i = i->next) {
        for (FlexLLNode<T>* j = i->next; j; j = j->next) {
            if (compare(i->data, j->data) > 0) {
                std::swap(i->data, j->data);
                sorted = false;
            }
        }
    }
    return sorted;
}

template <typename T>
bool FlexLL<T>::thin() {
    if (empty() || size == 1) return false;
    sort();
    
    bool removed = false;
    FlexLLNode<T>* curr = head;

    while (curr && curr->next) {
        if (compare(curr->data, curr->next->data) == 0) {
            FlexLLNode<T>* dup = curr->next;
            curr->next = dup->next;
            if (dup->next){
	      dup->next->prev = curr;
            }else{
	      tail = curr;
	    }
            delete dup;
            size--;
            removed = true;
        } else {
            curr = curr->next;
        }
    }
    return removed;
}

template <typename T>
FlexLL<T>& FlexLL<T>::prepend(FlexLL<T>& other, bool copy) {
    if (!copy && this == &other) return *this;

    if (copy) {
        FlexLLNode<T>* curr = other.tail;
        while (curr) {
            prepend(curr->data);
            curr = curr->prev;
        }
    } else {
        if (!other.head) return *this;
        other.tail->next = head;
        if (head) head->prev = other.tail;
        head = other.head;
        if (!tail) tail = other.tail;
        size += other.size;
    }

    return *this;
}

template <typename T>
bool FlexLL<T>::rewind() const{
    iterate = head;
    return (iterate != nullptr);
}

template <typename T>
bool FlexLL<T>::finished() const {
    return (iterate == nullptr);
}

template <typename T>
T FlexLL<T>::proceed() const{
    if (!iterate) return T();
    T data = iterate->data;
    iterate = iterate->next;
    return data;
}

#endif  // FLEXLL_CPP
