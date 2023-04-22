#include <iostream>

using namespace std;

class LinkedList {
public:
    struct Node {
        int data;
        Node* next;

        Node(int d, Node* n) {
            data = d;
            next = n;
        }
    };

    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void createList() {
        head = new Node(1, nullptr);
        head->next = nullptr;

        // create the rest of the nodes and link them together
        Node* current = head;
        for(int i = 2; i <= 5; i++) {
            current->next = new Node(i, nullptr);
            current = current->next;
        }

        // link the last node to the first node to create a circular list
        current->next = head;
    }

    void printList() {
        // print out the data in the circular list
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.createList();
    list.printList();
    return 0;
}
