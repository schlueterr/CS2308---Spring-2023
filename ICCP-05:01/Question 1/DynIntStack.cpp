#include "DynIntStack.h"

DynIntStack::~DynIntStack(){
    Node *temp;
    while(!isEmpty()){
        temp = head->next;
        delete head;
        head = temp;
    }
}

void DynIntStack::push(int num){
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = head;
    head = newNode;
}

int DynIntStack::pop(){
    assert(!isEmpty());
    int result = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    return result;
}