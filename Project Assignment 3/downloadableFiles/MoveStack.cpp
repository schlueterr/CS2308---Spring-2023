// Filename MoveStack.cpp
// Author: Braden Schlueter plr61
// Date: 05/01/2023
// Assignment Number: 3
// CS 2308 Sprin 2023
// Instructor: Xiaomin Li
//
// MoveStack A regular stack that stores instances of the Move structure. 
// A Move records the coordinates of the 'x' or 'o' token placed on the game board. 
// All past moves are stored here. The stack is required in order to be able to undo moves.


#include <cassert>
using namespace std;

#include "MoveStack.h"


MoveStack::MoveStack() { 
    head = nullptr;
}


MoveStack::~MoveStack() {
    Move *current = head;
    while (current != nullptr){
        Move *temp = current->next;
        delete current;
        current = temp; 
    }
}

//****************************************************
// Member function getsize returns a count of the    *
// number of elements on the stack.                  *
//****************************************************
int MoveStack::getSize() {
    Move *temp = head;
    int count = 0;
    while (temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
 }

//****************************************************
// Member function top returns the value at the top  *
// of the stack (does not remove it).                *
//****************************************************
Move MoveStack::top() {
    assert(head != nullptr);
    return *head;
}
//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
// move: the Move item to be pushed               *
//*************************************************
void MoveStack::push(Move move) {
    Move *temp = new Move;
    temp->x = move.x;
    temp->y = move.y;
    temp->next = nullptr;
    if (head == nullptr){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}
//****************************************************
// Member function pop removes the value at the top  *
// of the stack, but returns nothing.                *
//****************************************************
void MoveStack::pop() {
    Move *temp;
    temp = head;
    head = head->next;
    delete temp;
}
