#pragma once
#include "elem.h"
class stack {
private:
    size_t size;
    Elem* top;
public:
    stack() {
        size = 0;
        top = nullptr;
    }
    
    Node* getTop() { //returns an item from the stack without removing. O (1)
        return top->value;
    }

    void pop() //removes an item from the stack. O (1)
    {
        Elem* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    void push(Node* value) { //adds an item to the stack. O (1)
        top = new Elem(value, top);
        size++;
    }

    size_t getSize() {
        return size;
    }
    bool isEmpty() { //checks if the stack is empty. O (1)
        if (size == 0) return true;
        else return false;
    }

    void clear() {
        while (!isEmpty()) pop();
    }
};