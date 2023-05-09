#include <iostream>
using namespace std;

class Queue{
    private: 
        struct Node{
            int data;
            Node *next;
        };

    Node *front;
    Node *rear;

    public: 
        Queue(){
            front = nullptr;
            rear = nullptr;
        }
        bool isEmpty(){
            return front == nullptr;
        }

        void enqueue(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = nullptr;

            if (isEmpty()) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        int dequeue(){
            if (isEmpty()){
                cout << "Queue is empty. Cannot dequeue." << endl;
                return -1;
            }
            Node *temp = front;
            int value = temp->data;

            if (front == rear){
                front = nullptr;
                rear = nullptr;
            }
            else{
                front = front->next;
            }

            delete temp;
            return value;
        }

        int peek(){
            if (isEmpty()){
                cout << "Queue is empty. Cannot peek." << endl;
                return -1;
            }
            return front->data;
        }

};

int main(){
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.peek() << endl;

    while (!queue.isEmpty()){
        cout << "Dequeued element: " << queue.dequeue() << endl;
    }

    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
}