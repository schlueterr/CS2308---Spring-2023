#include "DynIntStack.h"

// g++ DynIntStack.cpp Question1.1.cpp -o testing


struct Node{
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* reverseLinkedList(Node* head){
    DynIntStack stack1; // To store the data of the linked list
    while (head != nullptr){ // Go though list and push data to stack
        stack1.push(head->data);
        head = head->next;
    }

    Node* newHead = nullptr;
    Node* temp = nullptr;
    while (!stack1.isEmpty()){
        int data = stack1.pop();
        Node* newNode = new Node(data);
        if (newHead == nullptr){
            newHead = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return newHead;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    Node* newHead = reverseLinkedList(head);

    cout << endl << "Reversed Linked List: ";
    while (newHead != nullptr){
        cout << newHead->data << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}