#pragma once
#include "elem.h"
class queue {
private:
    size_t size;
    Elem* begin, * end;
public:
    queue() {
        size = 0;
        begin = nullptr;
        end = nullptr;
    }
   

    Node* front() { //returns the element from the head of the queue without deleting. O (1)
        return begin->value;
    }

    Node* back() { //returns an item from the end of the queue without deleting it. O (1)
        return end->value;
    }

    bool isEmpty() { //checks if the queue is empty. O (1)
        if (size == 0) return true;
        else return false;
    }

    size_t getSize() {
        return size;
    }

    void push(Node* value) { //adds an item to the end of the queue. O (1)
        Elem* temp = new Elem(value, nullptr);
        if (isEmpty()) begin = temp;
        else end->next = temp;
        end = temp;
        size++;
    }

    void pop() { //removes the element from the head of the queue. O (1)
        Elem* temp = begin;
        begin = begin->next;
        delete temp;
        size--;
    }

    void clear() {
        while (!isEmpty()) pop();
    }
};
