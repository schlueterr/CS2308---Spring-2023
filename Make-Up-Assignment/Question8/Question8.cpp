#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class LinkedList{
    private: 
        Node *head;
    
    public:
        LinkedList(){
            head = nullptr;
        }

        void insert(int num){
            Node *newNode = new Node;
            newNode->data = num;
            newNode->next = head;
            head = newNode;
        }

        void remove(int num){
            Node *temp = head;
            Node *prev = nullptr;

            while (temp != nullptr && temp->data != num){
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr){
                cout << "Number not found" << endl;
            }
            else{
                if (prev == nullptr){
                    head = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
            }

            delete temp;
        }

        bool search(int num){
            Node *temp = head;

            while (temp != nullptr){
                if (temp->data == num){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void display(){
            Node *current = head;
            while (current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main(){
    LinkedList list1;


    list1.insert(5);
    list1.insert(10);
    list1.insert(15);
    list1.insert(24);

    cout << "List 1: ";
    list1.display();

    list1.remove(10);
    list1.remove(24);

    cout << "List 1 after removing 10 and 24: ";
    list1.display();

    cout << "Searching for 5: " << boolalpha << list1.search(5) << endl;
    cout << "Searching for 10: " << boolalpha << list1.search(10) << endl;

    return 0;

}