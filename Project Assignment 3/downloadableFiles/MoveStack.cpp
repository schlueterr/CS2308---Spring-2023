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

}


MoveStack::~MoveStack() {

}

//****************************************************
// Member function getsize returns a count of the    *
// number of elements on the stack.                  *
//****************************************************
int MoveStack::getSize() {

 }

//****************************************************
// Member function top returns the value at the top  *
// of the stack (does not remove it).                *
//****************************************************
Move MoveStack::top() {

}
//*************************************************
// Member function push pushes the argument onto  *
// the stack.                                     *
// move: the Move item to be pushed               *
//*************************************************
void MoveStack::push(Move move) {

};
//****************************************************
// Member function pop removes the value at the top  *
// of the stack, but returns nothing.                *
//****************************************************
void MoveStack::pop() {

}
